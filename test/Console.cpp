#include "Console.hpp"
#include "zghost/bus/Latch.hpp"
#include "zghost/bus/Memory.hpp"
#include <fstream>
#include <unistd.h>

Console::Console() {

    z80.getBusMemory().add("ROM", new Memory(0x0000, 0x0100, true));
    z80.getBusMemory().add("RAM", new Memory(0x0100, 0x0020, false));
    z80.getBusIO().add("PORTA", new Latch(0x0001));
    z80.getBusIO().add("PORTB", new Latch(0x0002));

    Memory* rom = (Memory*)z80.getBusMemory().get("ROM");
    std::ifstream instream("./bin/indexados.bin", std::ios::in | std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
    for (int i = 0; i < data.size(); i++)
        rom->getRaw()[i] = data[i];

    z80.reset();
}

Console::~Console() {}

void Console::exec() {

    Latch* porta = (Latch*)z80.getBusIO().get("PORTA");

    while (true) {
        z80.step();

        if (porta->isChanged()) {
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
