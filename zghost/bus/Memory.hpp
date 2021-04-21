#ifndef __MEMORY__HPP
#define __MEMORY__HPP

#include "Device.hpp"
#include "string"
#include "vector"

class Memory : public Device {
  public:
    Memory(const uint16_t& start, const uint16_t& size);
    virtual ~Memory();
    virtual std::tuple<uint8_t, bool> read(const uint16_t& address) override;
    virtual bool write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) override;

    void load(const std::string& file);

  private:
    // uint8_t* mem;
    std::vector<uint8_t> mem;
    uint16_t start;
    uint16_t top;
};

#endif
