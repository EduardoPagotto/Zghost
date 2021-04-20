#include "Console.hpp"
#include <unistd.h>

Console::Console() {

    rom = new Memory(0x0000, 0x0100);
    ram = new Memory(0x0100, 0x0100);

    portIn = new Latch(0x0001);
    portOut = new Latch(0x0002);

    bus.addMemory("rom", rom);
    bus.addMemory("ram", ram);
    bus.addIo("input", portIn);
    bus.addIo("output", portOut);

    rom->load("./bin/interrup1.bin");

    z80 = new Z80(&bus);
}

Console::~Console() {}

void Console::exec() {

    while (true) {
        z80->step();

        bool ok;
        uint8_t value;
        std::tie(value, ok) = portIn->readDirect();
        if (ok) {}

        if (z80->Halted) {
            z80->interrupt();
        }
        usleep(100);
    }
}
