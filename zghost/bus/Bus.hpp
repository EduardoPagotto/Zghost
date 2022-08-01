#pragma once
#include "Device.hpp"
#include <map>
#include <string>

enum class DeviceType { MEMORY, IO };

struct DevicePack {
    DevicePack() = default;
    ~DevicePack() = default;
    DevicePack(const DevicePack& o) = default;
    DevicePack(DeviceType type, const std::string& name, Device* dev) : type(type), name(name), device(dev) {}
    DeviceType type = DeviceType::MEMORY;
    Device* device = nullptr;
    std::string name;
};

class Bus {
  public:
    Bus() {}
    virtual ~Bus() {}
    Device* get(const uint16_t& index);
    Device* get(const std::string& name);
    uint16_t getIndex(const std::string& name);
    DeviceType getType(const uint16_t& index);
    uint16_t add(const DeviceType& type, const std::string& name, Device* dev);
    uint8_t read(const DeviceType& type, const uint16_t& address);
    void write(const DeviceType& type, const uint16_t& address, const uint8_t& value);

    void load(const std::string& file, uint16_t idDevice);

  private:
    std::vector<DevicePack> vDevs;
};
