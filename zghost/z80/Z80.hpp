#ifndef __Z80_HPP
#define __Z80_HPP

#include "R16.hpp"
#include <zghost/bus/Bus.hpp>

class Z80 {
  public:
    Z80(Bus* pBus);
    virtual ~Z80();
    void reset();
    void step();
    void interrupt();

    void push(const uint16_t& value);
    uint16_t pop();
    void pushR(R16* pReg);
    void popR(R16* pReg);

    void loadR(R16* pReg);
    uint16_t load16();
    uint8_t load8();

    void loadIndexR(R16* pReg);
    void storeIndexR(R16* pReg);
    void loadIndex8(uint8_t* pValue);
    void storeIndex8(const uint8_t& value);

    // private:
    uint8_t A, F, B, C, D, E, H, L;
    uint8_t A_, F_, B_, C_, D_, E_, H_, L_;
    uint8_t IXH, IXL, IYH, IYL;
    uint8_t I, IFF1, IFF2, IM;

    uint8_t R7; // byte // The highest bit (bit 7) of the R register
    uint16_t R;

    uint16_t pc;
    uint16_t sp;

    R16 *AF, *BC, *DE, *HL;
    R16 *IX, *IY;
    R16 *AF_, *BC_, *DE_, *HL_;

    bool Halted;
    uint16_t Tstates;
    uint16_t interruptsEnabledAt;
    uint16_t rzxInstructionsOffset;

    Bus* bus;
};

#endif