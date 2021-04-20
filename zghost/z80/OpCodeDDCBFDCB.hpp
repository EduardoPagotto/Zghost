#ifndef __OPCODEDDCBFDCB_H__
#define __OPCODEDDCBFDCB_H__

#include <zghost/z80/Z80.hpp>

void initOpCodeDDCBFDCB();
void opcodeDDCBFDCBStep(Z80* z, const uint8_t& opcode, const uint16_t& address);

#endif // __OPCODEDDCBFDCB_H__