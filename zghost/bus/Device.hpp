#pragma once
#include <cstdint>
#include <tuple>

class Device {
  public:
    virtual uint8_t read(const uint16_t& address) = 0;
    virtual void write(const uint16_t& address, const uint8_t& value) = 0;
    virtual bool valid(const uint16_t& address) = 0;
};
