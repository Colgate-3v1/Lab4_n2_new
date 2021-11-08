#include "Energy.h"

Energy::Energy() {}

Energy::Energy(double _v) :Base(_v)
{
    if (_v < 0)
        throw invalid_argument("massa >= 0");
}

Energy::Energy(const Energy& reference) :Base(reference)
{

}

Energy operator+(const Energy& left, const Energy& right)
{
    return Energy(left.get() + right.get());
}

Energy operator-(const Energy& left, const Energy& right)
{
    return Energy(left.get() - right.get());
}

ostream& operator<<(ostream& out, const Energy& obj)
{
    out << obj.get() << "J";
    return out;
}

Energy::operator Massa() const
{
    return Massa(this->get() / C / C);
}


Energy operator "" J(long double x)
{
    return Energy(x);
}

bool Energy::operator==(const Energy& massa) const noexcept
{
    return this->get() == massa.get();
}

std::partial_ordering Energy::operator<=>(const Energy& energy) const noexcept
{
    return this->get() <=> energy.get();
}