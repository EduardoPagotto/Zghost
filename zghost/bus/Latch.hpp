#ifndef __Latch__HPP
#define __Latch__HPP

#include "Device.hpp"

class Latch : public Device {
  public:
    Latch(const uint16_t& address);
    virtual ~Latch();
    virtual std::tuple<uint8_t, bool> read(const uint8_t& address) override;
    virtual bool write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) override;

  private:
    uint16_t address;
    uint8_t value;
};

#endif
