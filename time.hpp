#ifndef PERSONAL_CALENDAR_TIME_HPP
#define PERSONAL_CALENDAR_TIME_HPP

#include <iostream>


//! Клас за време, който има член-данни от тип unsigned за часове и минути
class Time
{
private:
    //! Цяло число показващо часовете със стойности от 0 до 24
    unsigned hours;
    //! Цяло число показващо минутите със стойности от 0 до 60
    unsigned minutes;
public:
    //! Конструктор с параметри
    Time(unsigned _hours = 0, unsigned _minutes = 0);

    //! Селектор за часове
    unsigned getHours() const
    { return hours; }

    //! Селектор за часове
    unsigned getMinutes() const
    { return minutes; }

    //! Мутатор за часове
    void setHours(unsigned _hours);

    //! Мутатор за минути
    void setMinutes(unsigned _minutes);

    friend std::istream& operator>>(std::istream&, Time&);
};

std::ostream& operator<<(std::ostream&, const Time&);

#endif //PERSONAL_CALENDAR_TIME_HPP
