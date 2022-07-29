#pragma once
#include "R16.hpp"
#include <zghost/bus/Bus.hpp>

#define FLAG_C 0b00000001 // Carry Flag
#define FLAG_N 0b00000010 // Add / Subtract Flag
#define FLAG_P 0b00000100 // Parity / Overflow Flag
#define FLAG_V FLAG_P
#define FLAG_3 0b00001000 // not used
#define FLAG_H 0b00010000 // Half Carry Flag
#define FLAG_5 0b00100000 // Not Used
#define FLAG_Z 0b01000000 // Zero Flag
#define FLAG_S 0b10000000 // Sign Flag

class Z80 {
  public:
    Z80();
    virtual ~Z80();
    void reset();
    void step();
    void interrupt();
    void nonMaskableInterrupt();

    Bus& getBusMemory() { return mem; }
    Bus& getBusIO() { return io; }

    void push(const uint16_t& value);
    uint16_t pop();
    void pushR16(R16& reg16);
    void popR16(R16& reg16);

    uint16_t load16();
    uint8_t load8();

    void loadIndexR16(R16& reg16);
    void storeIndexR16(R16& reg16);

    void call();
    void jr();
    void rst(const uint8_t& value);

    void oppAnd(const uint8_t& value);
    void oppXor(const uint8_t& value);
    void oppOr(const uint8_t& value);
    void oppCp(const uint8_t& value);

    void add(const uint8_t& value);
    void addR16(R16& value1, const uint16_t& value2);
    void adc(const uint8_t& value);
    void adc16(const uint16_t& value);
    void sub(const uint8_t& value);
    void sbc(const uint8_t& value);
    void sbc16(const uint16_t& value);
    void inc(uint8_t& value);
    void dec(uint8_t& value);

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

    void in(uint8_t* reg, const uint16_t& address);
    uint8_t readPort(const uint16_t& address);
    void writePort(const uint16_t& address, const uint8_t& b);

    void loadR16(R16& pReg);
    uint8_t readMem(const uint16_t& address);
    void writeMem(const uint16_t& address, const uint8_t& value);

    const uint8_t getRegVal(const uint8_t& opcode);
    uint8_t& getRegRef(const uint8_t& opcode);
    uint8_t getMaskBitReset(const uint8_t& opcode);

    uint8_t& getNull() { return null_val; }

    // private:
    uint8_t A, F, B, C, D, E, H, L;
    uint8_t A_, F_, B_, C_, D_, E_, H_, L_;
    uint8_t IXH, IXL, IYH, IYL;
    uint8_t I, IFF1, IFF2, IM;

    uint8_t R7; // byte // The highest bit (bit 7) of the R register
    uint16_t R;

    uint16_t pc;
    uint16_t sp;

    R16 AF, BC, DE, HL;
    R16 IX, IY;
    R16 AF_, BC_, DE_, HL_;

    bool Halted;
    uint16_t Tstates;
    uint16_t interruptsEnabledAt;
    uint16_t rzxInstructionsOffset;

    uint8_t sz53Table[256];
    uint8_t sz53pTable[256];
    uint8_t parityTable[256];

    const static uint8_t halfcarryAddTable[];
    const static uint8_t halfcarrySubTable[];
    const static uint8_t overflowAddTable[];
    const static uint8_t overflowSubTable[];

  private:
    void init_table_sz53();
    Bus mem;
    Bus io;
    uint8_t null_val = 0;
};
