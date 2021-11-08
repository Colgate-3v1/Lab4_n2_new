#include "Wave_length.h"
Wave_length::Wave_length()
{

}

Wave_length::Wave_length(double _v) :Base(_v)
{
    if (_v < 0)
        throw invalid_argument("massa >= 0");
}

Wave_length::Wave_length(const Wave_length& reference) :Base(reference)
{

}

Wave_length::operator Radiation_frequency() const
{
    return Radiation_frequency(C / this->get());
}

Wave_length operator+(const Wave_length& left, const Wave_length& right)
{
    return Wave_length(left.get() + right.get());
}

Wave_length operator-(const Wave_length& left, const Wave_length& right)
{
    return Wave_length(left.get() - right.get());
}




ostream& operator<<(ostream& out, const Wave_length& obj)
{
    out << obj.get();
    return out;
}
//istream& operator>>(istream& in, Wave_length& obj)
//{
//    in >> obj.value;
//    return in;
//}


Wave_length operator "" m(long double x)
{
    return Wave_length(x);
}

bool Wave_length::operator==(const Wave_length& massa) const noexcept
{
    return this->get() == massa.get();
}

std::partial_ordering Wave_length::operator<=>(const Wave_length& wave_length) const noexcept
{
    return this->get() <=> wave_length.get();
}