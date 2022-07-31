#pragma once
#include "Device.hpp"
#include <map>
#include <string>

enum class DeviceType { MEMORY, IO };

struct DevicePack {
    DevicePack() = default;
    ~DevicePack() = default;
    DevicePack(const DevicePack& o) = default;
    DevicePack(DeviceType type, Device* dev) : type(type), device(dev) {}
    DeviceType type = DeviceType::MEMORY;
    Device* device = nullptr;
};

class Bus {
  public:
    Bus() {}
    virtual ~Bus() {}
    Device* get(const uint16_t& id);
    DeviceType getType(const uint16_t& id);
    uint16_t add(const DeviceType& type, Device* dev);
    uint8_t read(const DeviceType& type, const uint16_t& address);
    void write(const DeviceType& type, const uint16_t& address, const uint8_t& value);

    void load(const std::string& file, uint16_t idDevice);

  private:
    std::map<uint16_t, DevicePack> mDevs;
};
