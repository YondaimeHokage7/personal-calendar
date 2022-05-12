#ifndef PERSONAL_CALENDAR_APPOINTMENT_HPP
#define PERSONAL_CALENDAR_APPOINTMENT_HPP

#include "date.hpp"
#include "time.hpp"
#include "timeInterval.hpp"

const size_t defaultNameSize{100};
const size_t defaultCommentSize{1000};

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
    /*//! Дата на срерщата
    Date date;
    //! Начало на срещата
    Time startTime;
    //! Край на срещата
    Time endTime;*/ // неизползвани член-данни

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

    //! Селекторр за час на начало
    unsigned getStartTimeH() const
    { return interval.getStartH(); }

    //! Селектор за минути на начало
    unsigned getStartTimeM() const
    { return interval.getStartM(); }

    //! Селектор за час на край
    unsigned getEndTimeH() const
    { return interval.getEndH(); }

    unsigned getEndTimeM() const
    { return interval.getEndM(); }

    //! Селектор за ден
    unsigned getStartDay() const
    { return interval.getStartDay(); }

    //! Селектор за месец
    unsigned getStartMonth() const
    { return interval.getStartMonth(); }

    //! Селектор за година
    int getStartYear() const
    { return interval.getStartYear(); }

    const char* getName() const
    { return name; }

    const char* getComment() const
    { return comment; }

    //! Мутатор за име
    void setName(const char* _name);

    //! Мутатор за коментар
    void setComment(const char* _comment);

    //! Мутатор за начална дата
    void setStartDate(unsigned _day = 1, unsigned _month = 1, int _year = 2022);

    //! Мутатор за време на начало на срещата
    void setStartTime(unsigned _hours = 0, unsigned _minutes = 0);

    //! Мутатор за крайна дата
    void setEndDate(unsigned _day = 1, unsigned _month = 1, int _year = 2022);

    //! Мутатор за време на край на срещата
    void setEndTime(unsigned _hours = 0, unsigned _minutes = 0);

    //! Предефиниране на >>
    friend std::istream& operator>>(std::istream&, Appointment&);

    //! Предефиниране на <<
    friend std::ostream& operator<<(std::ostream&, const Appointment&);
};

/*
*/ //неизползвани мутатори

#endif //PERSONAL_CALENDAR_APPOINTMENT_HPP
