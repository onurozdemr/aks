#include "ObjectManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

ObjectManager::ObjectManager() {
    for(int i = 0; i < 4; i++) {
        objects.push_back({i, "", false, false, false, false});
    }
    targetInfo = {0.0, 0.0, 0.0, 0.0, 0.0};    
    loadConfig("config.txt");
}

bool ObjectManager::loadConfig(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[AKS] Failed to open config file: " << path << "\n";
        return false;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        
        int slotNumber;
        std::string name;
        std::string healthStatus;
        
        if (!(iss >> slotNumber)) {
            continue; 
        }
        
        int index = slotNumber - 1; 
        if (index < 0 || index >= 4) {
            continue; 
        }
        
        if (iss >> name >> healthStatus) {
            objects[index].name = name;
            objects[index].isConnected = true;
            objects[index].isHealthy = (healthStatus == "OK");
            objects[index].isPowered = false;
            objects[index].isFired = false;
            std::cout << "[AKS] Loaded Slot " << slotNumber << ": " << name 
                      << " (" << (objects[index].isHealthy ? "Healthy" : "Unhealthy") << ")\n";
        } else {
            objects[index].name = "";
            objects[index].isConnected = false;
            objects[index].isHealthy = false;
            objects[index].isPowered = false;
            objects[index].isFired = false;
            std::cout << "[AKS] Loaded Slot " << slotNumber << ": Empty\n";
        }
    }
    
    file.close();
    return true;
}

void ObjectManager::powerOn(int index) {
    if (index < 0 || index >= 4) return;
    
    if (!objects[index].isConnected || !objects[index].isHealthy || objects[index].isFired) {
        std::cout << "[AKS] Cannot power Object " << index << " (Invalid state)\n";
        return;
    }
    
    for(auto& obj : objects) {
        obj.isPowered = false;
    }
    
    objects[index].isPowered = true;
    std::cout << "[AKS] Object " << index << " POWERED ON\n";
}

void ObjectManager::powerOff(int index) {
    if (index < 0 || index >= 4) return;
    
    if (objects[index].isPowered) {
        objects[index].isPowered = false;
        objects[index].fireStartTime = std::chrono::steady_clock::time_point(); 
        std::cout << "[AKS] Object " << index << " POWERED OFF\n";
    }
}

void ObjectManager::fire(int index) {
    if (index < 0 || index >= 4) return;
    
    if (objects[index].isPowered && objects[index].isHealthy) {
        std::cout << "[AKS] Firing Object " << index << "... (10s wait)\n";
        objects[index].fireStartTime = std::chrono::steady_clock::now();
    } else {
        std::cout << "[AKS] Failed to fire Object " << index << " (Not powered/healthy)\n";
    }
}

void ObjectManager::updateFiringLogic() {
    auto now = std::chrono::steady_clock::now();
    for(auto& obj : objects) {
        if (obj.isPowered && obj.isHealthy && !obj.isFired) {

            if (obj.fireStartTime.time_since_epoch().count() > 0) {
                 auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - obj.fireStartTime).count();
                 if (elapsed >= 10) {
                     obj.isPowered = false;
                     obj.isFired = true;
                     obj.fireStartTime = std::chrono::steady_clock::time_point(); 
                     std::cout << "[AKS] Object " << obj.id << " FIRED SUCCESSFULLY.\n";
                 }
            }
        }
    }
}

void ObjectManager::setTargetInfo(const TargetInfo& target) {
    targetInfo = target;
    std::cout << "[AKS] Target set: Lat=" << target.latitude 
              << ", Lon=" << target.longitude 
              << ", Alt=" << target.altitude 
              << ", Speed=" << target.speed 
              << ", Dist=" << target.distance << "\n";
}

const TargetInfo& ObjectManager::getTargetInfo() const {
    return targetInfo;
}

const std::vector<ObjectInfo>& ObjectManager::getObjects() const {
    return objects;
}