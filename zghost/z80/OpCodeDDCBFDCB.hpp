#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCodeDDCBFDCB();
void opcodeDDCBFDCBStep(Z80* z, const uint8_t& opcode, const uint16_t& address);
