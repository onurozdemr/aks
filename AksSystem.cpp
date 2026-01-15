#include "AksSystem.h"
#include "defs.h"
#include <iostream>

AksSystem::AksSystem()
{
    if(!socket.bindPort(PORT_AKS)) {
        std::cerr << "AKS socket failed";
    }
    lastHbSend = std::chrono::steady_clock::now();
    insConnected = false;
    launcherConnected = false;
    missedIns = 5;
    missedLauncher = 5;
}

ObjectManager& AksSystem::getObjManager() {
    return objManager;
}

void AksSystem::update() {
    auto now = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastHbSend).count() >= 1000) {
        HeartbeatMsg msg;
        msg.header.msgId = MSG_HEARTBEAT_AKS;
        msg.header.timestamp = 0; 
        msg.status = 0;

        socket.sendTo(&msg, sizeof(msg), "127.0.0.1", PORT_INS);
        socket.sendTo(&msg, sizeof(msg), "127.0.0.1", PORT_LAUNCHER);
        
        missedIns++;
        missedLauncher++;

        lastHbSend = now;
        
        if (missedIns >= 5 && insConnected) {
            insConnected = false;
            std::cout << "INS CONNECTION LOST !!!";
        }
        if (missedLauncher >= 5 && launcherConnected) {
            launcherConnected = false;
            std::cout << "LAUNCHER CONNECTION LOST !!!";
        }
    }

    char buffer[1024];
    int bytes = socket.receive(buffer, 1024);
    if (bytes > 0) {
        MessageHeader* header = (MessageHeader*)buffer;
        
        switch(header->msgId) {
            case MSG_HEARTBEAT_INS:
                missedIns = 0;
                if (!insConnected) {
                    insConnected = true;
                    std::cout << "[GUI] INS Connected (GREEN LED)\n";
                }
                break;
            case MSG_HEARTBEAT_LAUNCHER:
                missedLauncher = 0;
                if (!launcherConnected) {
                    launcherConnected = true;
                    std::cout << "[GUI] Launcher Connected (GREEN LED)\n";
                }
                break;
            case MSG_INS_DATA:
                if (bytes >= sizeof(InsDataMsg)) {
                    InsDataMsg* data = (InsDataMsg*)buffer;
                    std::cout << "[GUI] INS POS: " << data->latitude << ", " 
                              << data->longitude << ", " << data->altitude << "\n";
                }
                break;
        }
    }

    objManager.updateFiringLogic();
}