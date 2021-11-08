#pragma once
#include <iostream>
#include<compare>
#include "Base.h"

using namespace std;

class Temperature :public Base
{
public:
    Temperature();
    Temperature(double _v);
    Temperature(const Temperature& reference);

    Temperature(const Temperature&& reference) :Base(move(reference)) {   }
    virtual string get_string()
    {
        return to_string(this->get()) + "K";
    }
    Temperature& operator=(const Temperature& right)
    {
        return dynamic_cast<Temperature&>(Base::operator=(dynamic_cast<const Base&>(right)));
    }
    Temperature& operator=(Temperature&& right) {
        return dynamic_cast<Temperature&>(Base::operator=(dynamic_cast<Base&&>(right)));
    }


    //friend ostream& operator<<(ostream& out, const Temperature& obj);

    virtual ~Temperature() {}
    std::partial_ordering operator<=>(const Temperature&) const noexcept;
    bool operator==(const Temperature& temperature)const noexcept;
};
Temperature operator "" K(long double x);
Temperature operator+(const Temperature& left, const Temperature& right);
Temperature operator-(const Temperature& left, const Temperature& right);