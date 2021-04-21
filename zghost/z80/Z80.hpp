#ifndef __Z80_HPP
#define __Z80_HPP

#include "R16.hpp"
#include <zghost/bus/Bus.hpp>

#define FLAG_C 0x01
#define FLAG_N 0x02
#define FLAG_P 0x04
#define FLAG_V FLAG_P
#define FLAG_3 0x08
#define FLAG_H 0x10
#define FLAG_5 0x20
#define FLAG_Z 0x40
#define FLAG_S 0x80

class Z80 {
  public:
    Z80(Bus* pBus);
    virtual ~Z80();
    void reset();
    void step();
    void interrupt();
    void nonMaskableInterrupt();

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

    void call();
    void jr();
    void rst(const uint8_t& value);

    void oppAnd(const uint8_t& value);
    void oppXor(const uint8_t& value);
    void oppOr(const uint8_t& value);
    void oppCp(const uint8_t& value);

    void add(const uint8_t& value);
    void add16(R16* value1, const uint16_t& value2);
    void adc(const uint8_t& value);
    void adc16(const uint16_t& value);
    void sub(const uint8_t& value);
    void sbc(const uint8_t& value);
    void sbc16(const uint16_t& value);
    void inc(uint8_t* ptrValue);
    void dec(uint8_t* ptrValue);

    uint8_t rlc(const uint8_t& val);
    uint8_t rrc(const uint8_t& val);
    uint8_t rr(const uint8_t& val);
    uint8_t rl(const uint8_t& val);
    uint8_t sla(const uint8_t& val);
    uint8_t sll(const uint8_t& val);
    uint8_t sra(const uint8_t& val);
    uint8_t srl(const uint8_t& val);

    void bit(const uint8_t& bit, const uint8_t& value);
    void biti(const uint8_t& bit, const uint8_t& value, const uint16_t& address);

    void in(uint8_t* reg, const uint16_t& port);
    uint8_t readPort(const uint16_t& address);
    void writePort(const uint16_t& address, const uint8_t& b);

    uint8_t getRegisterValByte(const uint8_t& opcode);
    uint8_t* getPrtRegisterValByte(const uint8_t& opcode);
    uint8_t getMaskBitReset(const uint8_t& opcode);

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

    uint8_t sz53Table[256];
    uint8_t sz53pTable[256];
    uint8_t parityTable[256];

    const static uint8_t halfcarryAddTable[];
    const static uint8_t halfcarrySubTable[];
    const static uint8_t overflowAddTable[];
    const static uint8_t overflowSubTable[];

  private:
    void init_table_sz53();
};

#endif