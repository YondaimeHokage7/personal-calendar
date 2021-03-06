#include "date.hpp"

void Date::ensureValidDate()
{
    if (month < 1 || month > 12)
    {
        std::cout << "Invalid month!\n";
        std::cout << "Setting default month...\n";
        month = 1;
    }
    if (day < 1 || day > 31)
    {
        std::cout << "Invalid day!\n";
        std::cout << "Setting default day...\n";
        day = 1;
    }
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        std::cout << this->day;
        std::cout << "Invalid day!\n";
        std::cout << "Setting greatest possible value for a day in the given month...\n";
        day = 30;
    }
    if ((day > 28 && !this->isLeap() || day > 29 && this->isLeap()) && month == 2)
    {
        std::cout << "Invalid day!";
        std::cout << "Setting the greatest possible value for a day in February...\n";
        this->isLeap() ? day = 29 : day = 28;
    }
}

bool Date::isLeap()
{
    bool leapPrerequisite{year % 4 == 0};
    bool leapException{year % 100 == 0};
    bool leapExceptionOfTheException{year % 400 == 0};
    return leapPrerequisite && (!leapException || leapExceptionOfTheException);
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

bool Date::isInAnInterval(const Date& startDate, const Date& endDate) const
{
    bool betweenYears{startDate.getYear() < this->getYear() && this->getYear() < endDate.getYear()}; //minava 100%
    bool equalYears{startDate.getYear() == this->getYear() || this->getYear() == endDate.getYear()};
    bool betweenMonths(startDate.getMonth() < this->getMonth() && this->getMonth() < endDate.getMonth()); //minava 100% if equalYears == true
    bool equalMonths{startDate.getMonth() == this->getMonth() || this->getMonth() == endDate.getMonth()};
    bool betweenDays{startDate.getDay() < this->getDay() && this->getDay() < endDate.getDay()}; //minava 100% if equalMonths == true && equalYears
    bool equalDays{startDate.getDay() == this->getDay() || this->getDay() == endDate.getDay()};
    //BUG!!! (13-04-2002).isInInterval(12-04-2022, 14-04-2022) = true
    return (betweenYears) || (equalYears && betweenMonths) || (equalYears && equalMonths && betweenDays) || (equalDays && equalMonths && equalYears);
}

std::istream& operator>>(std::istream& is, Date& date)
{
    char c; //?????????? '-'
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

bool operator>(const Date& date1, const Date& date2)
{
    return (date1.getYear() > date2.getYear()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() > date2.getMonth()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() == date2.getMonth()) && (date1.getDay() > date2.getDay());
}

bool operator>=(const Date& date1, const Date& date2)
{
    return (date1.getYear() >= date2.getYear()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() >= date2.getMonth()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() == date2.getMonth()) && (date1.getDay() >= date2.getDay());
}


bool operator<(const Date& date1, const Date& date2)
{
    return (date1.getYear() < date2.getYear()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() < date2.getMonth()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() == date2.getMonth()) && (date1.getDay() < date2.getDay());

}

bool operator<=(const Date& date1, const Date& date2)
{
    return (date1.getYear() <= date2.getYear()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() <= date2.getMonth()) ||
           (date1.getYear() == date2.getYear()) && (date1.getMonth() == date2.getMonth()) && (date1.getDay() <= date2.getDay());

}

bool operator==(const Date& date1, const Date& date2)
{
    return date1.getYear() == date2.getYear() && date1.getMonth() == date2.getMonth() && date1.getDay() == date2.getDay();
}