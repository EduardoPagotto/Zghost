#pragma once
#include "Device.hpp"

class Latch : public Device {
  public:
    Latch(const uint16_t& address) : Device(true, false, false), address(address), value(0x0), invalid(0xff) {}
    virtual ~Latch() = default;
    virtual const uint8_t& read(const uint16_t& address) override;
    virtual void write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) const override { return (this->address == address); }

    const uint8_t& readDirect();
    void writeDirect(const uint8_t& value);

  private:
    uint16_t address = 0x0000;
    uint8_t value = 0xff;
    uint8_t invalid = 0xff;
    // bool hasVal = false;
};
