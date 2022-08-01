#include <fstream>
#include <zghost/bus/Bus.hpp>

Device* Bus::get(const uint16_t& index) { return this->vDevs[index].device; }

Device* Bus::get(const std::string& name) {
    for (auto& v : vDevs) {
        if (v.name == name)
            return v.device;
    }
    return nullptr;
}

uint16_t Bus::add(const DeviceType& type, const std::string& name, Device* dev) {
    size_t index = vDevs.size();
    vDevs.push_back(DevicePack(type, name, dev));
    return index;
}

uint16_t Bus::getIndex(const std::string& name) {
    uint16_t index = 0;
    for (auto& v : vDevs) {
        if (v.name == name)
            return index;
    }
    return -1;
}

DeviceType Bus::getType(const uint16_t& index) { return this->vDevs[index].type; }

uint8_t Bus::read(const DeviceType& type, const uint16_t& address) {
    uint8_t ret = 0xff;

    for (auto& v : vDevs) {
        if (v.type == type) {
            if (v.device->read(address, ret))
                return ret;
        }
    }

    return -1;
}

void Bus::write(const DeviceType& type, const uint16_t& address, const uint8_t& value) {

    for (auto& v : vDevs) {
        if (v.type == type) {
            if (v.device->write(address, value))
                return;
        }
    }
}

void Bus::load(const std::string& file, uint16_t index) {

    std::ifstream instream(file, std::ios::in | std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());

    Device* dev = get(index);
    for (int i = 0; i < data.size(); i++)
        dev->getRaw()[i] = data[i];
}