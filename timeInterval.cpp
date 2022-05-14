#include <sstream>
#include "timeInterval.hpp"
#include "time.hpp"

void TimeInterval::ensureValidInterval()
{
    if (this->startDate > this->endDate)
    {
        std::cout << "The starting date needs to be before the end date!";
        std::cout << "Swapping dates...";
        Date startPlaceholder;
        startPlaceholder = this->startDate;
        this->startDate = this->endDate;
        this->endDate = startPlaceholder;
    }
    if (this->startTime > this->endTime && this->startDate < this->endDate)
    {
        std::cout << "The starting time needs to be before the end time!";
        std::cout << "Swapping start time with end time...";
        Time startPlaceholder;
        startPlaceholder = this->startTime;
        this->startTime = this->endTime;
        this->endTime = startPlaceholder;
    }
}

TimeInterval::TimeInterval()
{
    ensureValidInterval();
}

TimeInterval::TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime) : startDate(_startDate), startTime(_startTime), endDate(_endDate), endTime(_endTime)
{
    ensureValidInterval();
}

bool TimeInterval::isBetween(const TimeInterval& interval1, const TimeInterval& interval2) const
{
    return (interval1.getStartDate() <= this->getStartDate() && this->getEndDate() <= interval2.getEndDate() && interval1.getStartTime() <= this->getStartTime() && this->getEndTime() <= interval2.getEndTime());
}

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

std::istream& operator>>(std::istream& is, TimeInterval& timeInterval)
{
    is >> timeInterval.startDate >> timeInterval.startTime >> timeInterval.endDate >> timeInterval.endTime;
    timeInterval.ensureValidInterval();
    return is;
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

TimeInterval& TimeInterval::operator=(const char* string)
{
    std::stringstream interval;
    interval << string;
    interval >> this->startDate >> this->startTime >> this->endDate >> this->endTime;
    ensureValidInterval();
    return *this;
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
