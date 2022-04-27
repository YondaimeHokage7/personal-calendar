#include "appointment.hpp"
#include "functions.hpp"

Appointment::Appointment()
{
    setName("Unknown");
    setComment("No comment");
}

Appointment::Appointment(const char* _name, const char* _comment, Date _date, Time _time) : date(_date), time(_time)
{
    setName(_name);
    setComment(_comment);
}

void Appointment::setComment(const char* _commenet)
{
    delete[] comment;
    comment = new char[strlen(_commenet)];
    strcpy(_commenet, comment);
}

void Appointment::setName(const char* _name)
{
    delete[] name;
    name = new char[strlen(_name)];
    strcpy(_name, name);
}

void Appointment::setTime(unsigned int _hours, unsigned int _minutes)
{
    time.setHours(_hours);
    time.setMinutes(_minutes);
}

void Appointment::setDate(unsigned int _day, unsigned int _month, int _year)
{
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
}