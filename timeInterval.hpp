#ifndef PERSONAL_CALENDAR_TIMEINTERVAL_HPP
#define PERSONAL_CALENDAR_TIMEINTERVAL_HPP

#include "time.hpp"
#include "date.hpp"

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

    //! Конструктор с параметри по подразбиране
    TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime);

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
    unsigned getStartYear() const
    { return startDate.getYear(); }

    //! Селектор за ден на край
    unsigned getEndDay() const
    { return endDate.getDay(); }

    //! Селектор за месец на край
    unsigned getEndMonth() const
    { return endDate.getMonth(); }

    //! Селектор за година на край
    unsigned getEndYear() const
    { return endDate.getYear(); }
};

#endif //PERSONAL_CALENDAR_TIMEINTERVAL_HPP
