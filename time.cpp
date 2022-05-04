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

std::istream& operator>>(std::istream& is, Time& t)
{
    char c; // държи ':'
    return is >> t.hours >> c >> t.minutes;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
    if (t.getHours() < 10 && t.getMinutes() < 10)
    {
        return os << 0 << t.getHours() << ':' << 0 << t.getMinutes();
    }
    else if (t.getHours() >= 10 && t.getMinutes() < 10)
    {
        return os << t.getHours() << ':' << 0 << t.getMinutes();
    }
    else if (t.getHours() < 10 && t.getMinutes() >= 10)
    {
        return os << 0 << t.getHours() << ':' << t.getMinutes();
    }
    return os << t.getHours() << ':' << t.getMinutes();
}