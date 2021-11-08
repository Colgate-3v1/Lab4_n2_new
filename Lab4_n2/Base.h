#pragma once
#include <iostream>
#include <memory>
#include <regex>
#include <string>
using namespace std;
class Base
{
private:
    double value;
protected:
    Base()
    {
        value = 0;
    }
    Base(double x)
    {
        value = x;
    }
    Base(const Base& x)
    {
        value = x.value;
    }
    Base(Base&& x)
    {
        value = x.value;
    }

    Base& operator=(const Base& right) {
        this->value = right.value;
        return *this;
    }
    Base& operator=(Base&& right) {
        this->value = right.value;
        return *this;
    }

    virtual ~Base()
    {
    }
public:
    virtual double get() const
    {
        return value;
    }
    virtual void set(double _value)
    {
        value = _value;
    }
    virtual string get_string()
    {
        return to_string(value);
    }
};
class Radiation_frequency;
class Energy;
class Massa;
class Temperature;
class Wave_length;