#pragma once
#include <cstdint>
#include <tuple>
#include <vector>

#define DSTAT_ENABLED 0x01   // status bitwise 0b00000001
#define DSTAT_CHANGED 0x02   // status bitwise 0b00000010
#define DSTAT_READWRITE 0x04 // status bitwise 0b00000100

enum class DevType { MEMORY = 0, IO = 1 };

class Device {
  public:
    Device(const uint8_t& status) : status(status) {}
    virtual ~Device() = default;
    virtual bool read(const uint16_t& address, uint8_t& valueRet) = 0;
    virtual bool write(const uint16_t& address, const uint8_t& value) = 0;

    inline const uint8_t& getStatus() { return status; }
    inline virtual void setToEnable() { this->status |= DSTAT_ENABLED; }
    inline virtual void setToDisable() { this->status &= (~DSTAT_ENABLED); }
    inline virtual std::vector<uint8_t>& getRaw() { return mem; }

  protected:
    std::vector<uint8_t> mem;
    uint8_t status = 0;
};
