#include "appointment.hpp"
#include "functions.hpp"
#include "features.hpp"

Appointment::Appointment() : name(new char[DEFAULT]), comment(new char[DEFAULT])
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
    myStrcpy(_comment, comment);
    comment[myStrlen(_comment) - 1] = '\0';
}


void Appointment::setName(const char* _name)
{
    delete[] name;
    name = new char[myStrlen(_name)];
    myStrcpy(_name, name);
    name[myStrlen(_name) - 1] = '\0';
}

std::istream& operator>>(std::istream& is, Appointment& appointment)
{
    if (&is == &std::cin)
    {
        return (is.getline(appointment.name, DEFAULT, '\n') >> appointment.interval).ignore(2).getline(appointment.comment, DEFAULT, '\n');
    }
    else
    {
        return (is.getline(appointment.name, DEFAULT, '\n') >> appointment.interval).ignore(1).getline(appointment.comment, DEFAULT, '\n');
    }
}

std::ostream& operator<<(std::ostream& os, const Appointment& appointment)
{
    return os << appointment.getName() << '\n' << appointment.getInterval() << '\n' << appointment.getComment() << '\n';
}

bool operator>(Appointment& app1, Appointment& app2)
{
    return (app1.getInterval() > app2.getInterval());
}

bool operator<(Appointment& app1, Appointment& app2)
{
    return (app1.getInterval() < app2.getInterval());
}

