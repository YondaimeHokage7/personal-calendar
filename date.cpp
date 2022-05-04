#include "date.hpp"

Date::Date(unsigned int _day, unsigned int _month, int _year) : day(_day), month(_month), year(_year)
{}

void Date::setDay(const unsigned _day)
{
    day = _day;
}

void Date::setMonth(const unsigned int _month)
{
    month = _month;
}

void Date::setYear(const int _year)
{
    year = _year;
}


std::istream& operator>>(std::istream& is, Date& date)
{
    char c; //държи '.'
    return is >> date.day >> c >> date.month >> c >> date.year;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    if (date.getDay() < 10 && date.getMonth() < 10)
    {
        return os << 0 << date.getDay() << '.' << 0 << date.getMonth() << '.' << date.getYear();
    }
    else if (date.getDay() >= 10 && date.getMonth() < 10)
    {
        return os << date.getDay() << '.' << 0 << date.getMonth() << '.' << date.getYear();
    }
    else if (date.getDay() < 10 && date.getMonth() >= 10)
    {
        return os << 0 << date.getDay() << '.' << date.getMonth() << '.' << date.getYear();
    }
    return os << date.getDay() << '.' << date.getMonth() << '.' << date.getYear();
}