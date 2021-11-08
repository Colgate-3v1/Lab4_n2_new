#pragma once
#pragma once
#include <iostream>
#include <compare>
#include <stdexcept>
#include "Constant.h"
#include "Base.h"


using namespace std;

class Massa :public Base
{
public:
    Massa();
    Massa(double _v);
    Massa(const Massa& reference);
    Massa(const Massa&& reference) :Base(move(reference)) {   }
    Massa& operator=(const Massa& right)
    {
        return dynamic_cast<Massa&>(Base::operator=(dynamic_cast<const Base&>(right)));
    }
    Massa& operator=(Massa&& right) {
        return dynamic_cast<Massa&>(Base::operator=(dynamic_cast<Base&&>(right)));
    }
    virtual ~Massa() {}
    std::partial_ordering operator<=>(const Massa&) const noexcept;
    bool operator==(const Massa& massa) const noexcept;
};

Massa operator "" kg(long double x);
Massa operator+(const Massa& left, const Massa& right);
Massa operator-(const Massa& left, const Massa& right);
ostream& operator<<(ostream& out, const Massa& obj);