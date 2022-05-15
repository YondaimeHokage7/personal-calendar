#include "time.hpp"

void Time::ensureValidTime()
{
    while (hours > 23)
    {
        std::cout << "Invalid value for hours!\n";
        std::cout << "Setting default value for hours\n";
        hours = 0;
    }
    while (minutes > 59)
    {
        std::cout << "Invalid value for minutes!\n";
        std::cout << "Setting default value for minutes\n";
        minutes = 0;
    }
}

Time::Time(unsigned int _hours, unsigned int _minutes) : hours(_hours), minutes(_minutes)
{
    ensureValidTime();
}

void Time::setHours(unsigned _hours)
{
    hours = _hours;
}

void Time::setMinutes(unsigned int _minutes)
{
    minutes = _minutes;
}

bool Time::isIn(const Time& time1, const Time& time2) const
{
    bool betweenHours{time1.getHours() <= this->getHours() && this->getHours() <= time2.getHours()};
    bool betweenMinutes{time1.getMinutes() < this->getMinutes() && this->getMinutes() < time2.getMinutes()};
    bool equalHours{time1.getHours() == this->getHours() || this->getHours() == time2.getHours()};
    return betweenHours || equalHours && betweenMinutes;
}

std::istream& operator>>(std::istream& is, Time& t)
{
    char c; // държи ':'
    is >> t.hours >> c >> t.minutes;
    t.ensureValidTime();
    return is;
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

bool operator>(const Time& time1, const Time& time2)
{
    return (time1.getHours() > time2.getHours()) ||
           (time1.getHours() == time2.getHours()) && (time1.getMinutes() > time2.getMinutes());
}

bool operator>=(const Time& time1, const Time& time2)
{
    return (time1.getHours() >= time2.getHours()) ||
           (time1.getHours() == time2.getHours()) && (time1.getMinutes() >= time2.getMinutes());
}

bool operator<(const Time& time1, const Time& time2)
{
    return (time1.getHours() < time2.getHours()) ||
           (time1.getHours() == time2.getHours()) && (time1.getMinutes() < time2.getMinutes());
}

bool operator<=(const Time& time1, const Time& time2)
{
    return (time1.getHours() <= time2.getHours()) ||
           (time1.getHours() == time2.getHours()) && (time1.getMinutes() <= time2.getMinutes());
}

bool operator==(const Time& time1, const Time& time2)
{
    return time1.getHours() == time2.getHours() && time1.getMinutes() == time2.getMinutes();
}
