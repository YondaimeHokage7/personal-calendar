#ifndef PERSONAL_CALENDAR_APPOINTMENT_HPP
#define PERSONAL_CALENDAR_APPOINTMENT_HPP

#include "date.hpp"
#include "time.hpp"
#include "timeInterval.hpp"


//! Клас за ангажимент, който има за член-данни два символни низа за име и коментар, Date за дата и Time за час
class Appointment
{
private:
    //! Име на срещата
    char* name;
    //! Коментар към срещата
    char* comment;
    //! Интервал от време
    TimeInterval interval;

public:

    //! Конструктор по подразбиране
    Appointment();

    //! Конструктор с параметри
    Appointment(const char* _name, const char* _comment, TimeInterval _interval);

    //! Конструктор за копиране
    Appointment(const Appointment&);

    //! Деструктор
    ~Appointment();

    TimeInterval getInterval() const
    { return interval; }

    const char* getName() const
    { return name; }

    const char* getComment() const
    { return comment; }

    //! Мутатор за име
    void setName(const char* _name);

    //! Мутатор за коментар
    void setComment(const char* _comment);

    //! Предефиниране на >>
    friend std::istream& operator>>(std::istream&, Appointment&);

    //! Предефиниране на <<
    friend std::ostream& operator<<(std::ostream&, const Appointment&);
};

bool operator>(Appointment&, Appointment&);

bool operator<(Appointment&, Appointment&);

#endif //PERSONAL_CALENDAR_APPOINTMENT_HPP
