#pragma once
#include <cstdint>
#include <tuple>

class Device {
  public:
    Device(const bool& enable, const bool& changed, const bool& readOnly) : enable(enable), changed(changed), readOnly(readOnly) {}
    virtual ~Device() = default;
    virtual const uint8_t& read(const uint16_t& address) = 0;
    virtual void write(const uint16_t& address, const uint8_t& value) = 0;
    virtual bool valid(const uint16_t& address) const = 0;

    inline virtual void setEnable(const bool& enable) { this->enable = enable; }
    // inline virtual void setReadyOnly(const bool& readOnly) { this->readOnly = readOnly; }
    inline virtual bool isChanged() const { return changed; }
    inline virtual bool isReadOnly() const { return readOnly; }

  protected:
    bool readOnly = false;
    bool enable = true;
    bool changed = false;
};
