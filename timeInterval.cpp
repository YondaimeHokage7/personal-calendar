#include <sstream>
#include "timeInterval.hpp"
#include "date.hpp"
#include "time.hpp"

void TimeInterval::ensureValidInterval()
{
    if (this->startDate > this->endDate)
    {
        std::cout << "The starting date needs to be before the end date!\n";
        std::cout << "Dates swapped\n";
        Date startPlaceholder;
        startPlaceholder = this->startDate;
        this->startDate = this->endDate;
        this->endDate = startPlaceholder;
    }
    if (this->startTime > this->endTime && this->startDate == this->endDate)
    {
        std::cout << "The starting time needs to be before the end time!\n";
        std::cout << "Start time swapped with end time\n";
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

bool TimeInterval::isIn(const TimeInterval& interval1) const
{
    bool isInDate{this->startDate.isInAnInterval(this->startDate,interval1.getStartDate())};
    bool equalDates{this->getStartDate() == interval1.getStartDate() || this->getStartDate() == interval1.getEndDate()};
    bool isInTime{interval1.getStartTime().isIn(interval1.getStartTime(),interval1.getEndTime())};
    return (isInDate || (equalDates && isInTime));
}

std::istream& operator>>(std::istream& is, TimeInterval& timeInterval)
{
    is >> timeInterval.startDate >> timeInterval.startTime >> timeInterval.endDate >> timeInterval.endTime;
    timeInterval.ensureValidInterval();
    return is;
}

std::ostream& operator<<(std::ostream& os, const TimeInterval& timeInterval)
{
    return os << timeInterval.getStartDate() << ' ' << timeInterval.getStartTime() << ' ' << timeInterval.getEndDate() << ' ' << timeInterval.getEndTime();
}

bool operator>(const TimeInterval& interval1, const TimeInterval& interval2)
{
    return (interval1.getStartDate() > interval2.getStartDate()) ||
           (interval1.getStartDate() == interval2.getStartDate()) && (interval1.getStartTime() > interval2.getStartTime());
}

bool operator==(const TimeInterval& interval1, const TimeInterval& interval2)
{
    return (interval1.getStartDate() == interval2.getStartDate()) && (interval1.getStartTime() == interval2.getStartTime()) && ((interval1.getEndDate()) == interval2.getEndDate()) && (interval1.getEndTime()==interval2.getEndTime());
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
