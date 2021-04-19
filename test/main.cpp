#include <zghost/bus/Latch.hpp>
#include <zghost/bus/Memory.hpp>
#include <zghost/z80/OpCode.hpp>
#include <zghost/z80/Z80.hpp>

int main(int argn, char** argv) {

    Bus bus;

    Memory rom(0x0000, 256);
    Memory ram(0x0100, 256);
    Latch port1(0x01);
    Latch port2(0x02);

    bus.addMemory("rom", &rom);
    bus.addMemory("ram", &ram);
    bus.addIo("port1", &port1);
    bus.addIo("port2", &port2);

    Z80* pZ80 = new Z80(&bus);
    pZ80->reset();

    OpCode opcode = OpCode();
    opcode.step(pZ80);

    // uint8_t h, l;
    // Register16* r = new Register16(&l, &h);

    return 0;
}