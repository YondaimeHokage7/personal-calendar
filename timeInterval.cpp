#include <sstream>
#include "timeInterval.hpp"
#include "time.hpp"
#include "functions.hpp"

TimeInterval::TimeInterval()
{}

TimeInterval::TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime) : startDate(_startDate), startTime(_startTime), endDate(_endDate), endTime(_endTime)
{}

//! Мутатор за начален ден
void TimeInterval::setStartDay(unsigned _day)
{
    startDate.setDay(_day);
}
//! Мутатор за начален месец
void TimeInterval::setStartMonth(unsigned _month)
{
    startDate.setMonth(_month);
}
//!Мутатор за начална година
void TimeInterval::setStartYear(int _year)
{
    startDate.setYear(_year);
}

//! Мутатор за начален час
void TimeInterval::setStartHours(unsigned _hours)
{
    startTime.setHours(_hours);
}

//!Мутатор за начални минути
void TimeInterval::setStartMinutes(unsigned _minutes)
{
    startTime.setHours(_minutes);
}

//! Мутатор за краен ден
void TimeInterval::setEndDay(unsigned _day)
{
    endDate.setDay(_day);
}

void TimeInterval::setEndMonth(unsigned int _month)
{
    endDate.setMonth(_month);
}

void TimeInterval::setEndYear(int _year)
{
    endDate.setYear(_year);
}

//! Мутатор за краен час
void TimeInterval::setEndHours(unsigned _hours)
{
    endTime.setHours(_hours);
}

//!Мутатор за крайни минути
void TimeInterval::setEndMinutes(unsigned _minutes)
{
    endTime.setMinutes(_minutes);
}

/*void TimeInterval::setStartDate(const Date& date)
{
    this->startDate = date;
}

void TimeInterval::setStartTime(const Time& time)
{
    this->startTime = time
}
void TimeInterval::setEndDate(const Date& date)
{
    this->endDate = date;
}
void TimeInterval::setEndTime(const Time& time)
{
    this->endTime = time;
}*/

std::istream& operator>>(std::istream& is, TimeInterval& timeInterval)
{
    return is >> timeInterval.startDate >> timeInterval.startTime >> timeInterval.endDate >> timeInterval.endTime;
}

std::ostream& operator<<(std::ostream& os, const TimeInterval& timeInterval)
{
    return os << timeInterval.startDate << ' ' << timeInterval.startTime << ' ' << timeInterval.endDate << ' ' << timeInterval.endTime;
    /*return os << timeInterval.getStartYear() << '-' << timeInterval.getStartMonth() << '-' << timeInterval.getStartDay() << ' ' << timeInterval.getStartH() << ':' << timeInterval.getStartM()
              << timeInterval.getEndYear() << '-' << timeInterval.getEndMonth() << '-' << timeInterval.getEndDay() << ' ' << timeInterval.getEndH() << ':' << timeInterval.getEndM();*/
}

bool operator>(const TimeInterval& interval1, const TimeInterval& interval2)
{
    return (interval1.getStartDate() > interval2.getStartDate()) ||
           (interval1.getStartDate() == interval2.getStartDate()) && (interval1.getStartTime() > interval2.getStartTime());
}

bool operator<(const TimeInterval& interval1, const TimeInterval& interval2)
{
    return (interval1.getStartDate() < interval2.getStartDate()) ||
           (interval1.getStartDate() == interval2.getStartDate()) && (interval1.getStartTime() < interval2.getStartTime());
}
