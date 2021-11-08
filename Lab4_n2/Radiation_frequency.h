#pragma once
#include <iostream>
#include<compare>
#include "Base.h"

using namespace std;

class Radiation_frequency :public Base
{
public:
    Radiation_frequency();

    Radiation_frequency(double _v);
    Radiation_frequency(const Radiation_frequency& reference);
    Radiation_frequency(const Radiation_frequency&& reference) :Base(move(reference)) {   }
    virtual string get_string()
    {
        return to_string(this->get()) + "Hz";
    }
    Radiation_frequency& operator=(const Radiation_frequency& right)
    {
        return dynamic_cast<Radiation_frequency&>(Base::operator=(dynamic_cast<const Base&>(right)));
    }
    Radiation_frequency& operator=(Radiation_frequency&& right) {
        return dynamic_cast<Radiation_frequency&>(Base::operator=(dynamic_cast<Base&&>(right)));
    }

    virtual ~Radiation_frequency() {}
    std::partial_ordering operator<=>(const Radiation_frequency&) const noexcept;
    bool operator==(const Radiation_frequency& radiation_frequency)const noexcept;
};
Radiation_frequency operator "" Hz(long double x);
Radiation_frequency operator+(const Radiation_frequency& left, const Radiation_frequency& right);
Radiation_frequency operator-(const Radiation_frequency& left, const Radiation_frequency& right);
ostream& operator<<(ostream& out, const Radiation_frequency& obj);