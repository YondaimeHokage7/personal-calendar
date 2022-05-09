#include "appointment.hpp"
#include "functions.hpp"

Appointment::Appointment() : name(new char[defaultNameSize]), comment(new char[defaultCommentSize])
{}

Appointment::Appointment(const char* _name, const char* _comment, TimeInterval _interval) : name(nullptr), comment(nullptr), interval(_interval)
{
    setName(_name);
    setComment(_comment);
}

Appointment::Appointment(const Appointment& other) : name(nullptr), comment(nullptr), interval(other.interval)
{
    setName(other.name);
    setComment(other.comment);
}

Appointment::~Appointment()
{
    delete[] name;
    delete[] comment;
}

void Appointment::setComment(const char* _comment)
{
    delete[] comment;
    comment = new char[myStrlen(_comment)];
    strcpy(_comment, comment);
    comment[myStrlen(_comment) - 1] = '\0';
}

void Appointment::setName(const char* _name)
{
    delete[] name;
    name = new char[myStrlen(_name)];
    strcpy(_name, name);
    name[myStrlen(_name) - 1] = '\0';
}

void Appointment::setStartDate(unsigned int _day, unsigned int _month, int _year)
{
    interval.setStartDay(_day);
    interval.setStartMonth(_month);
    interval.setStartYear(_year);
}

void Appointment::setStartTime(unsigned int _hours, unsigned int _minutes)
{
    interval.setStartHours(_hours);
    interval.setStartMinutes(_minutes);
}

void Appointment::setEndDate(unsigned int _day, unsigned int _month, int _year)
{
    interval.setEndDay(_day);
    interval.setEndMonth(_month);
    interval.setEndYear(_year);
}

void Appointment::setEndTime(unsigned int _hours, unsigned int _minutes)
{
    interval.setEndHours(_hours);
    interval.setEndMinutes(_minutes);
}

std::istream& operator>>(std::istream& is, Appointment& appointment)
{
    return (is.getline(appointment.name, myStrlen(appointment.name), '\n') >> appointment.interval).ignore().getline(appointment.comment, myStrlen(appointment.comment), '\n');
}

std::ostream& operator<<(std::ostream& os, const Appointment& appointment)
{
    return os << appointment.getName() << "\n" << appointment.interval << "\n" << appointment.getComment() << "\n";
}

/*void Appointment::setStartTime(unsigned int _hours, unsigned int _minutes)
{
    startTime.setHours(_hours);
    startTime.setMinutes(_minutes);
}

void Appointment::setEndTime(unsigned int _hours, unsigned int _minutes)
{
    endTime.setHours(_hours);
    endTime.setMinutes(_minutes);
}

void Appointment::setDate(unsigned int _day, unsigned int _month, int _year)
{
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
}*/ //неизползвани мутатори
