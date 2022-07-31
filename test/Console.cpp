#include "Console.hpp"
#include "zghost/bus/Latch.hpp"
#include "zghost/bus/Memory.hpp"
#include <unistd.h>

Console::Console() {

    idRom = bus.add(DeviceType::MEMORY, new Memory(0x0000, 0x0100, DSTAT_ENABLED));                                   // ROM
    idRam = bus.add(DeviceType::MEMORY, new Memory(0x0100, 0x0020, DSTAT_ENABLED | DSTAT_CHANGED | DSTAT_READWRITE)); // RAM
    idPortA = bus.add(DeviceType::IO, new Latch(0x0001, DSTAT_ENABLED | DSTAT_READWRITE));                            // PORT A
    idPortB = bus.add(DeviceType::IO, new Latch(0x0002, DSTAT_ENABLED | DSTAT_READWRITE));                            // PORT B

    bus.load("./bin/indexados.bin", idRom);

    z80.create(&bus);
    z80.reset();
}

Console::~Console() {}

void Console::exec() {

    Latch* porta = (Latch*)bus.get(idPortA);

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
