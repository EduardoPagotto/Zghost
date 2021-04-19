#ifndef __BUS_HPP
#define __BUS_HPP

#include "Device.hpp"
#include <map>

class Bus {
  public:
    Bus() {}
    virtual ~Bus() {}

    inline Device* getMemory(const std::string& name) { return this->mem[name]; }
    inline Device* getIo(const std::string& name) { return this->io[name]; }
    inline void addMemory(const std::string& name, Device* dev) { this->mem[name] = dev; }
    inline void addIo(const std::string& name, Device* dev) { this->io[name] = dev; }
    uint8_t readMemory(const uint16_t& address);
    void writeMemory(const uint16_t& address, const uint8_t& value);
    uint8_t readIo(const uint16_t& address);
    void writeIo(const uint16_t& address, const uint8_t& value);

  private:
    std::map<std::string, Device*> mem;
    std::map<std::string, Device*> io;
};

#endif
