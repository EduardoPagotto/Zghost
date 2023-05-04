#include <fstream>
#include <zghost/bus/Bus.hpp>

uint32_t Bus::add(Device* dev) {
    size_t index = vDevs.size();
    vDevs.push_back(dev);
    return index;
}

bool Bus::hasData(const uint32_t& address) const {
    for (auto& v : vDevs) {
        if (v->validRange(address, 0))
            return true;
    }
    return false;
}

uint8_t Bus::load(const uint32_t& address) {

    for (auto& v : vDevs) {
        uint8_t ret = 0xff;
        if (v->read(address, 1, &ret))
            return ret;
    }

    return -1;
}

void Bus::store(const uint32_t& address, const uint8_t& value) {

    for (auto& v : vDevs) {
        uint8_t vv = value;
        if (v->write(address, 1, &vv))
            return;
    }
}

void Bus::load(const std::string& file, uint16_t index) {

    std::ifstream instream(file, std::ios::in | std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());

    if (index < vDevs.size()) {
        Device* dev = vDevs[index];

        bool alterar = false;
        if (!dev->isRW()) {
            dev->setRW(true);
            alterar = true;
        }

        dev->write(dev->getStart(), data.size(), &data[0]);

        if (alterar)
            dev->setRW(false);
    }
}