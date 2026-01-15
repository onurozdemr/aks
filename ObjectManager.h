#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include <string>
#include <chrono>

struct ObjectInfo {
    int id;
    std::string name;
    bool isConnected;
    bool isHealthy;
    bool isPowered;
    bool isFired;
    std::chrono::steady_clock::time_point fireStartTime;
};

struct TargetInfo {
    double latitude;    
    double longitude;   
    double altitude;    
    double speed;       
    double distance;    
};

class ObjectManager {
public:
    ObjectManager();
    
    bool loadConfig(const std::string& path);
    
    void powerOn(int index);
    void powerOff(int index);
    void fire(int index);
    void updateFiringLogic();
    
    void setTargetInfo(const TargetInfo& target);
    const TargetInfo& getTargetInfo() const;
    
    
    const std::vector<ObjectInfo>& getObjects() const;

private:
    std::vector<ObjectInfo> objects;
    TargetInfo targetInfo;
};

#endif 