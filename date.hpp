#ifndef PERSONAL_CALENDAR_DATE_HPP
#define PERSONAL_CALENDAR_DATE_HPP
#include <iostream>

//! Клас за дата, който има член-данни от тип unsigned за ден и месец и от тип int за година
class Date
{
private:
    //! Положително число между 1 и 31 за ден
    unsigned day;
    //! Положително число между 1 и 12 за месец
    unsigned month;
    //! Цяло число за година
    int year;
public:
    //! Конструктор с параметри
    Date(unsigned _day = 1, unsigned _month = 1, int _year = 2022);

    //! Селектор за дни
    unsigned getDay() const
    { return day; }

    //! Селектор за месеци
    unsigned getMonth() const
    { return month; }

    //! Селектор за година
    int getYear() const
    { return year; }

    //! Мутатор за ден
    void setDay(const unsigned _day);
    //! Мутатор за месеци
    void setMonth(const unsigned _month);
    //! Мутатор за години
    void setYear(const int _year);

    friend std::istream& operator>>(std::istream&, Date&);
};

std::ostream& operator<<(std::ostream&, const Date&);

#endif //PERSONAL_CALENDAR_DATE_HPP