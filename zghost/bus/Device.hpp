#ifndef __DEVICE_HPP
#define __DEVICE_HPP

#include <cstdint>
#include <tuple>

class Device {
  public:
    // Device() {}
    // virtual ~Device() {}
    virtual std::tuple<uint8_t, bool> read(const uint8_t& address) = 0;
    virtual bool write(const uint16_t& address, const uint8_t& value) = 0;
    virtual bool valid(const uint16_t& address) = 0;
};

#endif