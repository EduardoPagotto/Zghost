#pragma once
#include "Device.hpp"
#include <map>
#include <string>

class Bus {
  public:
    Bus() {}
    virtual ~Bus() {}

    inline Device* get(const std::string& name) { return this->dev[name]; }
    inline void add(const std::string& name, Device* dev) { this->dev[name] = dev; }
    uint8_t read(const uint16_t& address);
    void write(const uint16_t& address, const uint8_t& value);

  private:
    std::map<std::string, Device*> dev;
};
