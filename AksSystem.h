#ifndef AKSSYSTEM_H
#define AKSSYSTEM_H

#include "UdpSocket.h"
#include "ObjectManager.h"
#include <chrono>

class AksSystem {
public:
    AksSystem();
    
    void update();
    ObjectManager& getObjManager();
    
    bool isInsConnected() const { return insConnected; }
    bool isLauncherConnected() const { return launcherConnected; }

private:
    UdpSocket socket;
    ObjectManager objManager;
    
    bool insConnected;
    bool launcherConnected;
    int missedIns;
    int missedLauncher;

    std::chrono::steady_clock::time_point lastHbSend;
};

#endif 