#pragma once

#include <iostream>

class Bottle {
public:
    Bottle() = default;
    Bottle(double volume, double fill_percent = 0);

    double GetVolume() const;
    double GetFillPercent() const;

    double GetFilledVolume() const;

private:
    double volume_ = 0;
    double fill_percent_ = 0;
};

double operator + (const Bottle& lhs, const Bottle& rhs);
double operator - (const Bottle& lhs, const Bottle& rhs);

bool operator == (const Bottle& lhs, const Bottle& rhs);
bool operator > (const Bottle& lhs, const Bottle& rhs);
bool operator < (const Bottle& lhs, const Bottle& rhs);

std::istream& operator >> (std::istream& is, Bottle& b);
std::ostream& operator << (std::ostream& os, const Bottle& b);

Bottle operator""_bottle(const char* str, size_t size);