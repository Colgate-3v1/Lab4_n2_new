#pragma once
#include <iostream>
#include <compare>
#include "Constant.h"
#include "Massa.h"
#include "Base.h"


using namespace std;

class Energy : public Base
{
public:
    Energy();
    Energy(const Energy& reference);
    Energy(Energy&& reference) :Base(move(reference)) {}
    Energy(double _v);

    Energy& operator=(const Energy& right)
    {
        return dynamic_cast<Energy&>(Base::operator=(dynamic_cast<const Base&>(right)));
    }
    Energy& operator=(Energy&& right) {
        return dynamic_cast<Energy&>(Base::operator=(dynamic_cast<Base&&>(right)));
    }
    operator Massa() const;
    virtual ~Energy() {};
    std::partial_ordering operator<=>(const Energy&) const noexcept;
    bool operator==(const Energy& energy) const noexcept;
};

Energy operator "" J(long double x);
Energy operator+(const Energy& left, const Energy& right);

Energy operator-(const Energy& left, const Energy& right);

ostream& operator<<(ostream& out, const Energy& obj);