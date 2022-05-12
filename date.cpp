#include "date.hpp"
#include "functions.hpp"

void Date::ensureValidDate()
{
    while (month < 1 || month > 12)
    {
        std::cout << "Invalid month!\n";
        std::cout << "Enter a valid month!";
        std::cin >> month;
    }
    while (day < 1 || day > 31)
    {
        std::cout << "Invalid day!\n";
        std::cout << "Enter a valid day";
        std::cin >> day;
    }
    while (day > 30 && month == 4 || month == 6 || month == 9 || month == 11)
    {
        std::cout << "Invalid day!";
        std::cout << "Enter a valid day!";
        std::cin >> day;
    }
    while (day > 28 && !isLeap(year) || day > 29 && isLeap(year))
    {
        std::cout << "Invalid day!";
        std::cout << "Enter a valid day!";
        std::cin >> day;
    }
}

Date::Date(unsigned int _day, unsigned int _month, int _year) : day(_day), month(_month), year(_year)
{
    ensureValidDate();
}

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

bool Date::isInAnInterval(const Date& startDate, const Date& endDate)
{
    bool betweenYears{startDate.getYear() < this->getYear() && this->getYear() < endDate.getYear()}; //minava 100%
    bool equalYears{startDate.getYear() == this->getYear() && this->getYear() == endDate.getYear()};
    bool betweenMonths(startDate.getMonth() <= this->getMonth() && this->getMonth() <= endDate.getMonth()); //minava 100% if equalYears == true
    bool equalMonths{startDate.getMonth() == this->getMonth() && this->getMonth() == endDate.getMonth()};
    bool betweenDays{startDate.getDay() <= this->getDay() && this->getDay() <= endDate.getDay()}; //minava 100% if equalMonths == true
    bool equalDays{startDate.getDay() == this->getDay() && this->getDay() == endDate.getDay()};
    //BUG!!! (13-04-2002).isInInterval(12-04-2022, 14-04-2022) = true
    return (betweenYears) || (equalYears && betweenMonths) || (equalYears && equalMonths && betweenDays) || (equalDays && equalMonths && equalYears);
}

std::istream& operator>>(std::istream& is, Date& date)
{
    char c; //държи '-'
    is >> date.day >> c >> date.month >> c >> date.year;
    date.ensureValidDate();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    if (date.getDay() < 10 && date.getMonth() < 10)
    {
        return os << 0 << date.getDay() << '-' << 0 << date.getMonth() << '-' << date.getYear();
    }
    else if (date.getDay() >= 10 && date.getMonth() < 10)
    {
        return os << date.getDay() << '-' << 0 << date.getMonth() << '-' << date.getYear();
    }
    else if (date.getDay() < 10 && date.getMonth() >= 10)
    {
        return os << 0 << date.getDay() << '-' << date.getMonth() << '-' << date.getYear();
    }
    return os << date.getDay() << '-' << date.getMonth() << '-' << date.getYear();
}