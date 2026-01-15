#ifndef SIMULATORS_H
#define SIMULATORS_H

#include "UdpSocket.h"
#include <chrono>

class Simulators {
public:
    Simulators();
    void update();

private:
    UdpSocket insSocket;
    UdpSocket launcherSocket;
    
    bool aksAlive;
    std::chrono::steady_clock::time_point lastSend;

    double lat, lon, alt;
};

#endif 

// This is for INS and Launcher heart beats