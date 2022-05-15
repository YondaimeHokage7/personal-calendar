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
    //! Подсигурява валиден интервал
    void ensureValidInterval();

public:

    //! Конструктор по подразбиране
    TimeInterval();

    //! Конструктор с параметри
    TimeInterval(Date _startDate, Time _startTime, Date _endDate, Time _endTime);

    //! Функция определяща дали интервал от време се съдържа в друг
    bool isIn(const TimeInterval&) const;

    //! Селектор за начална дата
    const Date& getStartDate() const
    { return startDate; }

    //! Селектор за начално време
    const Time& getStartTime() const
    { return startTime; }

    //! Селектор за крайна дата
    const Date& getEndDate() const
    { return endDate; }

    //! Селектор за крайно време
    const Time& getEndTime() const
    { return endTime; }

    //!Предефиниран оператор за въвеждане
    friend std::istream& operator>>(std::istream&, TimeInterval&);

    //! Предефиниран оператор за присвояване
    TimeInterval& operator=(const char*);
};
//! Предефиниран оператор за извеждане
std::ostream& operator<<(std::ostream&, const TimeInterval&);

//! Предефиниран оператор за сравнение на два интервала(строго)
bool operator>(const TimeInterval&, const TimeInterval&);

//! предефиниран оператор за равнество на два интервала
bool operator==(const TimeInterval&,const TimeInterval&);

//! Предефиниран оператор за сравнение на два интервала(строго)
bool operator<(const TimeInterval&, const TimeInterval&);

#endif //PERSONAL_CALENDAR_TIMEINTERVAL_HPP
