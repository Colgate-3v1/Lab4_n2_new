#pragma once
#include <iostream>
#include<compare>
#include "Radiation_frequency.h"
#include "Constant.h"
#include "Base.h"
using namespace std;

class Wave_length :public Base
{
public:
    Wave_length();
    Wave_length(double _v);
    Wave_length(const Wave_length& reference);
    virtual string get_string()
    {
        return to_string(this->get()) + "m";
    }
    Wave_length(const Wave_length&& reference) :Base(move(reference)) {   }
    Wave_length& operator=(const Wave_length& right)
    {
        return dynamic_cast<Wave_length&>(Base::operator=(dynamic_cast<const Base&>(right)));
    }
    Wave_length& operator=(Wave_length&& right) {
        return dynamic_cast<Wave_length&>(Base::operator=(dynamic_cast<Base&&>(right)));
    }


    operator Radiation_frequency()const;
    //friend istream& operator>>(istream& in, Wave_length& obj);
    //virtual ~Wave_length();
    std::partial_ordering operator<=>(const Wave_length&) const noexcept;
    bool operator==(const Wave_length& wave_length)const noexcept;
};
Wave_length operator "" m(long double x);
Wave_length operator+(const Wave_length& left, const Wave_length& right);
Wave_length operator-(const Wave_length& left, const Wave_length& right);
ostream& operator<<(ostream& out, const Wave_length& obj);