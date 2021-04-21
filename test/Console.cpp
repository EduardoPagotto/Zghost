#include "Console.hpp"
#include <unistd.h>

Console::Console() {

    rom = new Memory(0x0000, 0x0100);
    ram = new Memory(0x0100, 0x0020);

    portA = new Latch(0x0001);
    portB = new Latch(0x0002);

    bus.addMemory("rom", rom);
    bus.addMemory("ram", ram);
    bus.addIo("portA", portA);
    bus.addIo("portB", portB);

    rom->load("./bin/indexados.bin");

    z80 = new Z80(&bus);
    z80->reset();
}

Console::~Console() {}

void Console::exec() {

    while (true) {
        z80->step();

        bool ok;
        uint8_t value;
        std::tie(value, ok) = portA->readDirect();
        if (ok) {
            printf("Recebido: %d\n", value);
        }

        if (z80->Halted) {
            z80->interrupt();
        }
        usleep(100);
    }
}
