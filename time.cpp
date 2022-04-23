#include "time.hpp"

Time::Time(unsigned int _hours, unsigned int _minutes) : hours(_hours), minutes(_minutes)
{}

void Time::setHours(unsigned _hours)
{
    hours = _hours;
}

void Time::setMinutes(unsigned int _minutes)
{
    minutes = _minutes;
}