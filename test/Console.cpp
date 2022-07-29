#include "Console.hpp"
#include "zghost/bus/Latch.hpp"
#include "zghost/bus/Memory.hpp"
#include <unistd.h>

Console::Console() {

    z80.getBusMemory().add("ROM", new Memory(0x0000, 0x0100));
    z80.getBusMemory().add("RAM", new Memory(0x0100, 0x0020));
    z80.getBusIO().add("PORTA", new Latch(0x0001));
    z80.getBusIO().add("PORTB", new Latch(0x0002));

    Memory* rom = (Memory*)z80.getBusMemory().get("ROM");
    rom->load("./bin/indexados.bin");

    z80.reset();
}

Console::~Console() {}

void Console::exec() {

    Latch* porta = (Latch*)z80.getBusMemory().get("PORTA");

    while (true) {
        z80.step();

        bool ok;
        uint8_t value;
        value = porta->readDirect();
        printf("Recebido: %d\n", value);

        if (z80.Halted) {
            z80.interrupt();
        }
        usleep(100);
    }
}
