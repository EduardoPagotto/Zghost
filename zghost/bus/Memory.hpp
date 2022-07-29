#pragma once
#include "Device.hpp"
#include "string"
#include "vector"

class Memory : public Device {
  public:
    Memory(const uint16_t& start, const uint16_t& size, const bool& readOnly);
    virtual ~Memory();
    virtual const uint8_t& read(const uint16_t& address) override;
    virtual void write(const uint16_t& address, const uint8_t& value) override;
    inline virtual bool valid(const uint16_t& address) const override { return ((address >= start) && (address < top)); }
    inline std::vector<uint8_t>& getRaw() { return mem; }

  private:
    std::vector<uint8_t> mem;
    uint16_t start = 0x0000;
    uint16_t top = 0x4000;
    bool readOnly = false;
};
