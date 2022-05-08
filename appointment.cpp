#include "appointment.hpp"
#include "functions.hpp"

Appointment::Appointment() : name(nullptr), comment(nullptr)
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
    comment = new char[strlen(_comment)];
    strcpy(_comment, comment);
    comment[strlen(_comment) - 1] = '\0';
}

void Appointment::setName(const char* _name)
{
    delete[] name;
    name = new char[strlen(_name)];
    strcpy(_name, name);
    name[strlen(_name) - 1] = '\0';
}

std::istream& operator>>(std::istream& is, Appointment& appointment)
{
    return (is.getline(appointment.name, SIZE_MAX, '\n') >> appointment.interval).ignore().getline(appointment.comment, SIZE_MAX, '\n');
}

std::ostream& operator<<(std::ostream& os, Appointment& appointment)
{
    return os << appointment.getName() << ' ' << appointment.interval << ' ' << appointment.getComment();
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
