#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <vector>

struct SocketControl {
    std::vector<int> controls;
    int frames;
    // 0 = not pressed
    // 1 = pressed
    int state;
};

int SocketInit(int);
void Send(const char*);
int GetSocketFrame();
std::vector<unsigned char> Receive();
int GetSocketFrames();
//Queue Stuff
void EmptyControllerQueue();
void ProcessToController(std::vector<unsigned char>);
std::vector<SocketControl> GetControlsQueue();
std::vector<SocketControl> UnpressedControls();
void ReduceFrame();
void SetButtonState(int index);
void CloseSocket();

#endif