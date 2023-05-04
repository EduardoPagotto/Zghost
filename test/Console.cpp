#include "Console.hpp"
#include "zghost/bus/Latch.hpp"
#include "zghost/bus/Memory.hpp"
#include <unistd.h>

Console::Console() {

    z80.createMemory(&busMemory);
    z80.createIO(&busIO);
    z80.reset();
}

Console::~Console() {}

void Console::exec() {

    uint32_t idRom = busMemory.add(new Memory(0x0000, 0x0200, DEV_OPENED));          // ROM
    uint32_t idRam = busMemory.add(new Memory(0x0200, 0x0100, DEV_OPENED | DEV_RW)); // RAM
    uint32_t idPortA = busIO.add(new Latch(0x0001, DEV_OPENED | DEV_RW));            // PORT A
    uint32_t idPortB = busIO.add(new Latch(0x0002, DEV_OPENED | DEV_RW));            // PORT B

    busMemory.load("./bin/main.bin", idRom);

    Latch* porta = (Latch*)busIO.get(idPortA);

    while (true) {
        z80.step();

        if (porta->getStatus() & DEV_CHANGED) {
            uint8_t value;
            if (porta->readDirect(value))
                printf("Recebido: %d\n", value);
        }

        if (z80.Halted) {
            z80.interrupt();
        }
        usleep(100);
    }
}
