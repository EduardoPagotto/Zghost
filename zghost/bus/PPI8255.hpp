#pragma once
#include "Device.hpp"

class PPI8255 : public Device {

  public:
    PPI8255(const uint16_t& address);
    virtual ~PPI8255();
    virtual uint8_t& read(const uint16_t& address) override;
    virtual void write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) const override;

    uint8_t& inA();
    uint8_t& inB();
    uint8_t& inC();

    void outA(const uint8_t& value);
    void outB(const uint8_t& value);
    void outC(const uint8_t& value);

    void bsr();

  private:
    void change();

    uint16_t addressBase = 0x0000;
    uint8_t portA = 0;
    uint8_t portB = 0;
    uint8_t portC = 0;
    uint8_t control = 0;

    uint8_t invalid = 0xff;
    uint8_t defaultC = 0xff;
    // interruptA;
    // interruptB;
    // changedHandler;
};
