#pragma once
#include <cstdint>
#include <tuple>

#define DSTAT_ENABLED 0b00000001
#define DSTAT_CHANGED 0b00000010
#define DSTAT_READONLY 0b00000100

class Device {
  public:
    Device(const uint8_t& status) : status(status) {}
    virtual ~Device() = default;
    virtual bool read(const uint16_t& address, uint8_t& valueRet) = 0;
    virtual bool write(const uint16_t& address, const uint8_t& value) = 0;
    virtual bool valid(const uint16_t& address) const = 0;

    inline const uint8_t& getStatus() { return status; }
    inline virtual void setToEnable() { this->status |= DSTAT_ENABLED; }
    inline virtual void setToDisable() { this->status &= (!DSTAT_ENABLED); }

  protected:
    uint8_t status = DSTAT_ENABLED;
};
