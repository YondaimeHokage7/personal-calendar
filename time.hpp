#ifndef PERSONAL_CALENDAR_TIME_HPP
#define PERSONAL_CALENDAR_TIME_HPP

#include <iostream>


//! Клас за време, който има член-данни от тип unsigned за часове и минути
class Time
{
private:
    //! Цяло число показващо часовете със стойности от 0 до 23
    unsigned hours;
    //! Цяло число показващо минутите със стойности от 0 до 59
    unsigned minutes;
    //! Функция подсигуряваща валдиност на час
    void ensureValidTime();
public:
    //! Конструктор с параметри
    Time(unsigned _hours = 0, unsigned _minutes = 0);

    //! Селектор за часове
    unsigned getHours() const
    { return hours; }

    //! Селектор за минути
    unsigned getMinutes() const
    { return minutes; }

    //! Мутатор за часове
    void setHours(unsigned _hours);

    //! Мутатор за минути
    void setMinutes(unsigned _minutes);

    //! Функция проверяваща дали даден час е между два други часа
    bool isIn(const Time&, const Time&) const;

    //! Предефиниран оператор за въвеждане а Time
    friend std::istream& operator>>(std::istream&, Time&);
};
//! Предефиниран оператор за извеждане на Time
std::ostream& operator<<(std::ostream&, const Time&);

//! Предефиниран оператор за сравнение на Time с Time (строго)
bool operator>(const Time&, const Time&);

//! Предефиниран оператор за сравнение на Time с Time (нестрого)
bool operator>=(const Time&, const Time&);

//! Предефиниран оператор за сравнение на Time с Time (строго)
bool operator<(const Time&, const Time&);

//! Предефиниран оператор за сравнение на Time с Time (нестрого)
bool operator<=(const Time&, const Time&);

//! Предефиниран оператор за равенство на Time и Time
bool operator==(const Time&, const Time&);

#endif //PERSONAL_CALENDAR_TIME_HPP
