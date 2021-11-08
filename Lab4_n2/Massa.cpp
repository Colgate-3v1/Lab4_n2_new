#include "Massa.h"

Massa::Massa()
{

}

Massa::Massa(double _v) :Base(_v)
{
    if (_v < 0)
        throw invalid_argument("massa >= 0");
}

Massa::Massa(const Massa& reference) :Base(reference)
{

}


Massa operator+(const Massa& left, const Massa& right)
{
    return Massa(left.get() + right.get());
}

Massa operator-(const Massa& left, const Massa& right)
{
    return Massa(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Massa& obj)
{
    out << obj.get() << "kg";
    return out;
}




Massa operator "" kg(long double x)
{
    return Massa(x);
}

bool Massa::operator==(const Massa& massa) const noexcept
{
    return this->get() == massa.get();
}


std::partial_ordering Massa::operator<=>(const Massa& massa) const noexcept
{
    return this->get() <=> massa.get();
}
