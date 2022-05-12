#ifndef PERSONAL_CALENDAR_TIMEINTERVAL_HPP
#define PERSONAL_CALENDAR_TIMEINTERVAL_HPP

#include "time.hpp"
#include "date.hpp"
#include <iostream>

//! Клас за интервал от време
class TimeInterval
{
private:
    //! Начална дата
    Date startDate;
    //! Крайна дата
    Date endDate;
    //! Начално време
    Time startTime;
    //! Крайно време
    Time endTime;
public:

    //! Конструктор по подразбиране
    TimeInterval();

    //! Конструктор с параметри
    TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime);

    //! Селектор за начална дата
    Date getStartDate() const
    { return startDate; }

    //! Селектор за начално време
    Time getStartTime() const
    { return startTime; }

    //! Селектор за крайна дата
    Date getEndDate() const
    { return endDate; }

    //! Селектор за крайно време
    Time getEndTime() const
    { return endTime; }

    //! Селектор за час на начало време
    unsigned getStartH() const
    { return startTime.getHours(); }

    //! Селектор за минути на начало време
    unsigned getStartM() const
    { return startTime.getMinutes(); }

    //! Селектор за часове на край
    unsigned getEndH() const
    { return endTime.getHours(); }

    //! Селектор за миннути на край
    unsigned getEndM() const
    { return endTime.getMinutes(); }

    //!Селектор за ден на начална дата
    unsigned getStartDay() const
    { return startDate.getDay(); }

    //! Селектор за месец на начална дата
    unsigned getStartMonth() const
    { return startDate.getMonth(); }

    //! Селектор за година за начална дата
    int getStartYear() const
    { return startDate.getYear(); }

    //! Селектор за ден на край
    unsigned getEndDay() const
    { return endDate.getDay(); }

    //! Селектор за месец на край
    unsigned getEndMonth() const
    { return endDate.getMonth(); }

    //! Селектор за година на край
    int getEndYear() const
    { return endDate.getYear(); }


    //! Мутатор за начален ден
    void setStartDay(unsigned _day);

    //! Мутатор за нчален месец
    void setStartMonth(unsigned _month);

    //! Мутатор за начална година
    void setStartYear(int _year);

    //! Мутатор за начален час
    void setStartHours(unsigned _hours);

    //!Мутатор за начални минути
    void setStartMinutes(unsigned _minutes);

    //! Мутатор за краен ден
    void setEndDay(unsigned _day);

    //!Мутатор за краен месец
    void setEndMonth(unsigned _month);

    //! Мутатор за крайна година
    void setEndYear(int _year);

    //! Мутатор за краен час
    void setEndHours(unsigned _hours);

    //!Мутатор за крайни минути
    void setEndMinutes(unsigned _minutes);

    friend std::istream& operator>>(std::istream&, TimeInterval&);

    friend std::ostream& operator<<(std::ostream&, const TimeInterval&);
};


#endif //PERSONAL_CALENDAR_TIMEINTERVAL_HPP
