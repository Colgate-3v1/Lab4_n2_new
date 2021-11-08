#include "Radiation_frequency.h"

Radiation_frequency::Radiation_frequency()
{

}

Radiation_frequency::Radiation_frequency(double _v) :Base(_v)
{
    if (_v < 0)
        throw invalid_argument("massa >= 0");
}

Radiation_frequency::Radiation_frequency(const Radiation_frequency& reference) :Base(reference)
{

}

Radiation_frequency operator+(const Radiation_frequency& left, const Radiation_frequency& right)
{
    return Radiation_frequency(left.get() + right.get());
}

Radiation_frequency operator-(const Radiation_frequency& left, const Radiation_frequency& right)
{
    return Radiation_frequency(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Radiation_frequency& obj)
{
    out << obj.get() << "Hz";
    return out;
}

Radiation_frequency operator "" _Hz(long double x)
{
    return Radiation_frequency(x);
}

bool Radiation_frequency::operator==(const Radiation_frequency& massa) const noexcept
{
    return this->get() == massa.get();
}

std::partial_ordering Radiation_frequency::operator<=>(const Radiation_frequency& Radiation_frequency) const noexcept
{
    return this->get() <=> Radiation_frequency.get();
}