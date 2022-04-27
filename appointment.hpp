#ifndef PERSONAL_CALENDAR_APPOINTMENT_HPP
#define PERSONAL_CALENDAR_APPOINTMENT_HPP

#include "date.hpp"
#include "time.hpp"

//! Клас за ангажимент, който има за член-данни два символни низа за име и коментар, Date за дата и Time за час
class Appointment
{
private:
    //! Име на срещата
    char* name;
    //! Коментар към срещата
    char* comment;
    //! Дата на срерщата
    Date date;
    //! Време на срещата
    Time time;
public:

    //! Конструктор по подразбиране
    Appointment();

    //! Конструктор с параметри
    Appointment(const char* _name, const char* _comment, Date _date, Time _time);

    //! Селекторр за часове
    unsigned getTimeH() const
    { return time.getHours(); }

    //! Селектор за минути
    unsigned getTimeM() const
    { return time.getMinutes(); }

    //! Селектор за ден
    unsigned getDay() const
    { return date.getDay(); }

    //! Селектор за месец
    unsigned getMonth() const
    { return date.getMonth(); }

    //! Селектор за година
    int getYear() const
    { return date.getYear(); }

    //! Мутатор за име
    void setName(const char* _name);

    //! Мутатор за коментар
    void setComment(const char* _commenet);

    //! Мутатор за време
    void setTime(unsigned _hours = 0, unsigned _minutes = 0);

    //! Мутатор за дата
    void setDate(unsigned _day = 1, unsigned _month = 1, int _year = 2022);
};

#endif //PERSONAL_CALENDAR_APPOINTMENT_HPP
