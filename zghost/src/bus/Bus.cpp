#include <fstream>
#include <zghost/bus/Bus.hpp>

Device* Bus::get(const uint16_t& id) { return this->mDevs[id].device; }

uint16_t Bus::add(const DeviceType& type, Device* dev) {

    size_t size = mDevs.size();
    mDevs[size] = DevicePack(type, dev);
    return size;
}

DeviceType Bus::getType(const uint16_t& id) { return this->mDevs[id].type; }

uint8_t Bus::read(const DeviceType& type, const uint16_t& address) {
    uint8_t ret = 0xff;

    for (auto it = mDevs.begin(); it != mDevs.end(); it++) {

        DevicePack pDev = it->second;
        if (pDev.type == type) {
            if (pDev.device->read(address, ret))
                return ret;
        }
    }
    return ret;
}

void Bus::write(const DeviceType& type, const uint16_t& address, const uint8_t& value) {
    for (auto it = mDevs.begin(); it != mDevs.end(); it++) {

        DevicePack pDev = it->second;
        if (pDev.type == type) {
            if (pDev.device->write(address, value))
                return;
        }
    }
}

void Bus::load(const std::string& file, uint16_t idDevice) {

    std::ifstream instream(file, std::ios::in | std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());

    Device* dev = get(idDevice);
    for (int i = 0; i < data.size(); i++)
        dev->getRaw()[i] = data[i];
}