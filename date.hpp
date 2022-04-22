#ifndef PERSONAL_CALENDAR_DATE_HPP
#define PERSONAL_CALENDAR_DATE_HPP

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
    //! Конструктор по подразбиране
    Date();

    //! Конструктор с параметри
    Date(unsigned _day, unsigned _month, int year);

    //! Селектор за дни
    unsigned getDay() const
    {
        return day;
    }
    //! Селектор за месеци
    unsigned getMonth() const
    {
        return month;
    }
    //! Селектор за година
    int getYear() const
    {
        return year;
    }
};
#endif //PERSONAL_CALENDAR_DATE_HPP