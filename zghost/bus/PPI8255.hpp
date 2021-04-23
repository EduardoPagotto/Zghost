#ifndef __PPI8255_H__
#define __PPI8255_H__

#include "Device.hpp"

class PPI8255 : public Device {

  public:
    PPI8255(const uint16_t& address);
    virtual ~PPI8255();
    virtual std::tuple<uint8_t, bool> read(const uint16_t& address) override;
    virtual bool write(const uint16_t& address, const uint8_t& value) override;
    virtual bool valid(const uint16_t& address) override;

    std::tuple<uint8_t, bool> inA();
    bool outA(const uint8_t& value);
    std::tuple<uint8_t, bool> inB();
    bool outB(const uint8_t& value);
    std::tuple<uint8_t, bool> inC();
    bool outC(const uint8_t& value);

    void bsr();

  private:
    void change();

    uint16_t addressBase;
    uint8_t portA;
    uint8_t portB;
    uint8_t portC;
    uint8_t control;

    // interruptA;
    // interruptB;
    // changedHandler;
};

#endif // __PPI8255_H__