#include "Temperature.h"

Temperature::Temperature()
{

}

Temperature::Temperature(double _v) :Base(_v)
{
    if (_v < 0)
        throw invalid_argument("massa >= 0");
}

Temperature::Temperature(const Temperature& reference) :Base(reference)
{

}


Temperature operator+(const Temperature& left, const Temperature& right)
{
    return Temperature(left.get() + right.get());
}

Temperature operator-(const Temperature& left, const Temperature& right)
{
    return Temperature(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Temperature& obj)
{
    out << obj.get() << "T";
    return out;
}

Temperature operator "" K(long double x)
{
    return Temperature(x);
}

bool Temperature::operator==(const Temperature& massa) const noexcept
{
    return this->get() == massa.get();
}

std::partial_ordering Temperature::operator<=>(const Temperature& temperature) const noexcept
{
    return this->get() <=> temperature.get();
}