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
};

#endif //PERSONAL_CALENDAR_APPOINTMENT_HPP
