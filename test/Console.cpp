#include "Console.hpp"
#include "zghost/bus/Latch.hpp"
#include "zghost/bus/Memory.hpp"
#include <unistd.h>

Console::Console() {

    uint16_t idRom = bus.add(DeviceType::MEMORY, "ROM", new Memory(0x0000, 0x0200, DSTAT_ENABLED));                   // ROM
    uint16_t idRam = bus.add(DeviceType::MEMORY, "RAM", new Memory(0x0200, 0x0100, DSTAT_ENABLED | DSTAT_READWRITE)); // RAM
    uint16_t idPortA = bus.add(DeviceType::IO, "PortA", new Latch(0x0001, DSTAT_ENABLED | DSTAT_READWRITE));          // PORT A
    uint16_t idPortB = bus.add(DeviceType::IO, "PortB", new Latch(0x0002, DSTAT_ENABLED | DSTAT_READWRITE));          // PORT B

    bus.load("./bin/main.bin", idRom);

    z80.create(&bus);
    z80.reset();
}

Console::~Console() {}

void Console::exec() {

    Latch* porta = (Latch*)bus.get("PortA");

    while (true) {
        z80.step();

        if (porta->getStatus() & DSTAT_CHANGED) {
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
