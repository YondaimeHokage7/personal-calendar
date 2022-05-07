#ifndef PERSONAL_CALENDAR_TIMEINTERVAL_HPP
#define PERSONAL_CALENDAR_TIMEINTERVAL_HPP

#include "time.hpp"


class TimeInterval
{
private:
    Time start;
    Time end;
public:
    TimeInterval(Time _start, Time _end);

    unsigned getStartH() const
    { return start.getHours(); }

    unsigned getStartM() const
    { return start.getMinutes(); }

    unsigned getEndH() const
    { return end.getHours(); }

    unsigned getEndM() const
    { return end.getMinutes(); }
};

#endif //PERSONAL_CALENDAR_TIMEINTERVAL_HPP
