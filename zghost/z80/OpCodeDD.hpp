#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCodeDD();
void opcodeDDStep(Z80* z, const uint8_t opcode);
