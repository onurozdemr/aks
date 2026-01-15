#include "Simulators.h"
#include "defs.h"

Simulators::Simulators() {
    
    insSocket.bindPort(PORT_INS);
    launcherSocket.bindPort(PORT_LAUNCHER);
    lastSend = std::chrono::steady_clock::now();
    aksAlive = false;
    lat = 30.0;
    lon = 40.0;
    alt = 100.0;
}

void Simulators::update() {
    char buffer[1024];
    
    // INS socket AKS signal
    if (insSocket.receive(buffer, 1024) > 0) {
        MessageHeader* h = (MessageHeader*)buffer;
        if (h->msgId == MSG_HEARTBEAT_AKS) 
            aksAlive = true;
    }
    
    // Launcher socket AKS signal
    if (launcherSocket.receive(buffer, 1024) > 0) {
        MessageHeader* h = (MessageHeader*)buffer;
        if (h->msgId == MSG_HEARTBEAT_AKS) 
            aksAlive = true;
    }

    auto now = std::chrono::steady_clock::now();
    if (aksAlive && std::chrono::duration_cast<std::chrono::milliseconds>(now - lastSend).count() >= 1000) {
        
        // INS Heartbeat
        HeartbeatMsg insHb;
        insHb.header.msgId = MSG_HEARTBEAT_INS;
        insSocket.sendTo(&insHb, sizeof(insHb), "127.0.0.1", PORT_AKS);

        // INS Data
        InsDataMsg insData;
        insData.header.msgId = MSG_INS_DATA;
        insData.latitude = lat;
        insData.longitude = lon;
        insData.altitude = alt;
        insSocket.sendTo(&insData, sizeof(insData), "127.0.0.1", PORT_AKS);
        
        lat += 1.0; lon += 1.0;
        
        // Lanucher Heartbeat
        HeartbeatMsg lchHb;
        lchHb.header.msgId = MSG_HEARTBEAT_LAUNCHER;
        launcherSocket.sendTo(&lchHb, sizeof(lchHb), "127.0.0.1", PORT_AKS);

        lastSend = now;
    }
}