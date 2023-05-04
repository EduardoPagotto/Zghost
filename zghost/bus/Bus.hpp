#pragma once
#include "Device.hpp"
#include <map>
#include <string>

class Bus {
  public:
    Bus() {}
    virtual ~Bus() {}
    uint32_t add(Device* dev);
    Device* get(const uint32_t& index) { return vDevs[index]; }
    bool hasData(const uint32_t& address) const;

    uint8_t load(const uint32_t& address);
    void store(const uint32_t& address, const uint8_t& value);

    void load(const std::string& file, uint16_t idDevice);

  private:
    std::vector<Device*> vDevs;
};
