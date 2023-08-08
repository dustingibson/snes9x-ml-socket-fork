#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <vector>

struct SocketControl {
    std::vector<int> controls;
    int frames;
};

int SocketInit(void);
void Send(const char*);
int GetSocketFrame();
std::vector<unsigned char> Receive();

//Queue Stuff
void EmptyControllerQueue();
void ProcessToController(std::vector<unsigned char>);
std::vector<SocketControl> GetControlsQueue();
std::vector<SocketControl> UnpressedControls();
void ReduceFrame();

#endif