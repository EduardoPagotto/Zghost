#pragma once
#include "Memory.hpp"

class PPI8255 : public Memory {

  public:
    PPI8255(const uint16_t& address, const uint8_t& status);
    virtual ~PPI8255();
    virtual bool read(const uint16_t& address, uint8_t& valueRet) override;
    virtual bool write(const uint16_t& address, const uint8_t& value) override;

    void strobeA();
    void strobeB();

  private:
    uint8_t inA();
    uint8_t inB();
    uint8_t inC();

    void outA(const uint8_t& value);
    void outB(const uint8_t& value);
    void outC(const uint8_t& value);
    void bsr();

    void change();
    void SetInterruptCallPA(void* call);
    void SetInterruptCallPB(void* call);

    void* interruptA = nullptr;
    void* interruptB = nullptr;
    void* changedHandler = nullptr;
};
