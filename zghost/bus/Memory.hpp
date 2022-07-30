#pragma once
#include "Device.hpp"
#include "string"
#include "vector"

class Memory : public Device {
  public:
    Memory(const uint16_t& start, const uint16_t& size, const uint8_t& status);
    virtual ~Memory();
    virtual bool read(const uint16_t& address, uint8_t& valueRet) override;
    virtual bool write(const uint16_t& address, const uint8_t& value) override;
    inline virtual bool valid(const uint16_t& address) const override {
        return ((status & DSTAT_ENABLED) && (address >= start) && (address < top));
    }
    inline std::vector<uint8_t>& getRaw() { return mem; }

  protected:
    std::vector<uint8_t> mem;
    uint16_t start = 0x0000;
    uint16_t top = 0x4000;
};
