#include "bottle.h"
#include <exception>
#include <stdexcept>
#include <sstream>

Bottle::Bottle(double volume, double fill_percent)
: volume_(volume), fill_percent_(fill_percent) {
    if (volume < 0 || fill_percent < 0 || fill_percent > 1) {
        throw std::logic_error("Unacceptable parameters for constructor");
    }
}

double Bottle::GetVolume() const {
    return volume_;
}

double Bottle::GetFillPercent() const {
    return fill_percent_;
}

double Bottle::GetFilledVolume() const {
    return volume_ * fill_percent_;
}

double operator + (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() + rhs.GetFilledVolume();
}

double operator - (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() - rhs.GetFilledVolume();
}

bool operator == (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() == rhs.GetFilledVolume();
}

bool operator > (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() > rhs.GetFilledVolume();
}

bool operator < (const Bottle& lhs, const Bottle& rhs) {
    return lhs.GetFilledVolume() < rhs.GetFilledVolume();
}

Bottle operator""_bottle(const char* str, size_t size) {
    std::stringstream ss(str);
    Bottle res;
    ss >> res;
    return res;
}

std::istream& operator >> (std::istream& is, Bottle& b) {
    double volume, percent;
    is >> volume >> percent;
    b = Bottle(volume, percent);
    return is;
}

std::ostream& operator << (std::ostream& os, const Bottle& b) {
    return os << "Volume:" <<b.GetVolume() << ", Fill percent:" << b.GetFillPercent() << ", Filled volume:" << b.GetFilledVolume();
}