#include "timeInterval.hpp"
#include "time.hpp"

TimeInterval::TimeInterval()
{}

TimeInterval::TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime) : startDate(_startDate), startTime(_startTime), endDate(_endDate), endTime(_endTime)
{}

std::istream& operator>>(std::istream& is, TimeInterval& timeInterval)
{
    return is >> timeInterval.startDate >> timeInterval.startTime >> timeInterval.endDate >> timeInterval.endTime;
}

std::ostream& operator<<(std::ostream& os, const TimeInterval& timeInterval)
{
    return os << timeInterval.startDate << ' ' <<timeInterval.startTime << ' ' << timeInterval.endDate << ' ' <<timeInterval.endTime;
    /*return os << timeInterval.getStartYear() << '-' << timeInterval.getStartMonth() << '-' << timeInterval.getStartDay() << ' ' << timeInterval.getStartH() << ':' << timeInterval.getStartM()
              << timeInterval.getEndYear() << '-' << timeInterval.getEndMonth() << '-' << timeInterval.getEndDay() << ' ' << timeInterval.getEndH() << ':' << timeInterval.getEndM();*/
}

