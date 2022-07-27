#ifndef __REGISTER16__HPP
#define __REGISTER16__HPP

#include <cstdint>
#include <tuple>

class R16 {
  public:
    R16(uint8_t* high, uint8_t* low) : high(high), low(low) {}
    inline const uint8_t getHi() const { return *this->high; }
    inline const uint8_t getLo() const { return *this->low; }
    inline const uint16_t get() const { return joinBytes(*this->high, *this->low); }

    inline void setHi(const uint8_t& val) { *this->high = val; }
    inline void setLo(const uint8_t& val) { *this->low = val; }
    inline void set(const uint16_t& val) { std::tie(*this->high, *this->low) = R16::splitword(val); }

    inline void inc() { std::tie(*this->high, *this->low) = R16::splitword(this->get() + 1); }
    inline void dec() { std::tie(*this->high, *this->low) = R16::splitword(this->get() - 1); }

    inline static std::tuple<uint8_t, uint8_t> splitword(uint16_t w) { return std::make_tuple(w >> 8, w & 0xff); }
    inline static uint16_t joinBytes(const uint8_t& h, const uint8_t& l) { return static_cast<uint16_t>((h << 8) | l); }
    inline static int16_t signExtend(const uint8_t& v) { return static_cast<int16_t>(static_cast<int8_t>(v)); }

  private:
    uint8_t* low;
    uint8_t* high;
};

#endif