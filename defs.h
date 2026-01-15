#ifndef DEFS_H
#define DEFS_H

#include <cstdint>

const int PORT_AKS = 10000;
const int PORT_INS = 10001;
const int PORT_LAUNCHER = 10002;


enum MessageType : uint8_t {
    MSG_HEARTBEAT_AKS = 0x01,
    MSG_HEARTBEAT_INS = 0x02,
    MSG_HEARTBEAT_LAUNCHER = 0x03,
    MSG_INS_DATA = 0x04
};

#pragma pack(push, 1)

struct MessageHeader {
    uint8_t msgId;
    uint64_t timestamp; 
};

struct HeartbeatMsg {
    MessageHeader header;
    uint8_t status; 
};

struct InsDataMsg {
    MessageHeader header;
    double latitude;
    double longitude;
    double altitude;
};

#pragma pack(pop)

#endif 