#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   
#include <arpa/inet.h>    
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>

#include "socket.h"

#define PORT 5500

int ClientSocket;
int frame = 0;
std::vector<SocketControl> ControlsQueue;

int SocketInit()
{
    std::cout << "Initalizing socket" << std::endl;
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        printf("Unable to create socket");
        return -1;
    }
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr*) &hint, sizeof(hint)) == -1)
    {
        printf("Unable to bind");
        return -2;
    }

    if (listen(listening, SOMAXCONN) == -1)
    {
        printf("Unable to listen");
        return -3;
    }

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    ClientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host, 0, NI_MAXHOST);
    memset(service, 0 , NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service,  NI_MAXSERV, 0) == 0)
    {
        //printf("Connected on port %s", service);
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        //printf("Connected on port %i", ntohs(client.sin_port));
    }
    close(listening);
    
    return 0;
}

void Send(const char* buf)
{
    int size = 15;
    frame++;
    send(ClientSocket, buf, sizeof(buf)*size, 0);
}

int GetSocketFrame()
{
    return frame;
}

std::vector<unsigned char> Receive()
{
    std::vector<unsigned char> buffer(4096, 0);
    int bytesReceived = recv(ClientSocket, buffer.data(), buffer.size(), 0);
    if (bytesReceived <= 0)
    {
        std::cout << "Unable to receive from client" << std::endl;
        return buffer;
    }
    ProcessToController(buffer);
    return buffer;
}

void ReduceFrame()
{
    for (auto it = ControlsQueue.begin(); it != ControlsQueue.end(); it++) {
        it->frames--;
    }   
}

std::vector<SocketControl> UnpressedControls() 
{
    std::vector<SocketControl> controls;
    for (auto it = ControlsQueue.begin(); it != ControlsQueue.end(); it++) {
        if (it->frames <= 0)
            controls.push_back(*it);
    }
    return controls;
}

void EmptyControllerQueue()
{
    for (int i = 0; i < ControlsQueue.size(); i++) {
        if (ControlsQueue[i].frames <= 0) {
            ControlsQueue.erase(ControlsQueue.begin() + i);
            EmptyControllerQueue();
        }
    }
}

std::vector<SocketControl> GetControlsQueue()
{
    return ControlsQueue;
}

int GetInt(std::vector<unsigned char> data, int cnt)
{
    int curControl = 0;
    curControl = (curControl << 8) + (uint32_t)data[cnt];
    curControl = (curControl << 8) + (uint32_t)data[cnt+1];
    curControl = (curControl << 8) + (uint32_t)data[cnt+2];
    curControl = (curControl << 8) + (uint32_t)data[cnt+3];
    return curControl;
}

int GetInt16(std::vector<unsigned char> data, int cnt)
{
    int curControl = 0;
    curControl = (curControl << 8) + (uint32_t)data[cnt];
    curControl = (curControl << 8) + (uint32_t)data[cnt+1];

    return curControl;
}

void ProcessToController(std::vector<unsigned char> data)
{
	int cnt =  0;
	while (cnt < data.size())
	{
		unsigned char curByte = data[cnt];
		switch ( (int)curByte ) {
			case 1:
			{
				if ((int)data[cnt+1] == 2)
				{
					cnt++;
				}
				else
				{
					cnt++;
					std::cout << "Detected controller!" << std::endl;
                    std::vector<int> allControls;

                    // Peak into the next two bytes, is it end of it or holding more buttons?
                    while(data[cnt+2] != 2)
                    {
					    allControls.push_back(GetInt(data, cnt));
                        cnt += 4;
                    }

                    int curFrame = GetInt16(data, cnt);
                    cnt += 2;

                    SocketControl socketControl = { allControls, curFrame};
                    ControlsQueue.push_back(socketControl);
				}
				break;
			}
			case 2:
				cnt++;
				if ((int)data[cnt+1] == 100)
					break;
				break;
			case 100:
				return;
			case 0:
				return;
			default:
				break;
		}
	}

    // TODO: Safetly close out of socket when snes9x closes
}