#pragma once
#include "Device.hpp"

class Latch : public Device {
  public:
    Latch(const uint16_t& address) : address(address), value(0x0), hasVal(false) {}
    virtual ~Latch() = default;
    virtual uint8_t read(const uint16_t& address) override;
    virtual void write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) override { return (this->address == address); }

    uint8_t readDirect();
    void writeDirect(const uint8_t& value);

  private:
    uint16_t address = 0x0000;
    uint8_t value = 0xff;
    bool hasVal = false;
};
