#include <fstream>
#include <sstream>
#include "features.hpp"
#include "appointment.hpp"
#include "functions.hpp"

void printInstructions()
{
    std::cout << "What would you like to do?\n";
    std::cout << "\"Create\" to create an event\n";
    std::cout << "\"Delete\" to delete an event\n";
    std::cout << "\"Schedule\" to see a chronological schedule for a day\n";
    std::cout << "\"Change\" to change an event\n";
    std::cout << "\"Search\" to search for an event\n";
    std::cout << "\"Busyness\" presents the most busy days\n";
    std::cout << "\"Free\" searches for a free time in a given interval\n";
}

void create()
{
    std::cout << "Appointment: \n";
    Appointment appointment;
    std::cin >> appointment;
    std::ofstream f("appointments.txt", std::ios::app);
    if (f.is_open())
    {
        f << appointment;
    }
    else
    {
        std::cout << "Error!";
    }
}

void deleteEvent()
{
    std::cout << "Appointment: \n";
    Appointment appointment;
    std::cin >> appointment;
    Appointment read;
    std::ifstream f("appointments.txt", std::ios::in);
    if (f.is_open())
    {
        std::stringstream saved;
        while (f.good())
        {
            f >> read;
            bool notEmpty{read.getName()[0] != 0};
            if (notEmpty && !(myStrcmp(appointment.getName(), read.getName()) && compareIntervals(appointment.getInterval(), read.getInterval()) && myStrcmp(appointment.getComment(), read.getComment())))
            {
                saved << read.getName() << '\n' << read.getInterval() << '\n' << read.getComment() << '\n';
            }
        }
        f.close();
        std::ofstream ofs("appointments.txt", std::ios::trunc);
        ofs << saved.str();
    }
    else
    {
        std::cerr << "Error!";
    }
}

void schedule()
{
    //Може когато се създават още да са сортирани
    std::stringstream toBePrinted;
    std::cout << "Enter a date: ";
    Date date;
    std::cin >> date;
    std::ifstream fi("appointments.txt", std::ios::in);
    TimeInterval interval;
    std::stringstream intervals;
    std::stringstream trash;
    char* name{new char[DEFAULT]};
    char* intervalStr{new char[34]};
    char* comment{new char[DEFAULT]};
    while (fi.good())
    {
        fi.getline(name, DEFAULT, '\n');
        fi.getline(intervalStr, 34, '\n');
        intervals << intervalStr;
        intervals >> interval;
        fi.getline(comment, DEFAULT, '\n');
        if (date.isInAnInterval(interval.getStartDate(), interval.getEndDate()))
        {
            if (!(myStrcmp(name, intervalStr) && myStrcmp(intervalStr, comment)))
            {
                toBePrinted << name << '\n' << intervalStr << '\n' << comment << '\n';
            }
        }
    }
    fi.close();
    delete[] name;
    delete[] intervalStr;
    delete[] comment;
    std::cout << toBePrinted.str();
}

void change()
{
    char* name{new char[DEFAULT]{}};
    char* intervalString{new char[34]{}};
    char* comment{new char[DEFAULT]{}};
    std::stringstream changed;
    std::stringstream allIntervals;
    TimeInterval interval;
    TimeInterval originalInterval;
    std::cout << "Eevent name: ";
    std::cin.getline(name, DEFAULT, '\n');
    std::cout << "Enter time interval: ";
    std::cin.getline(intervalString, 34, '\n');
    interval = intervalString;
    originalInterval = interval;
    std::ifstream appointments("appointments.txt", std::ios::in);
    char* nameRead{new char[DEFAULT]{}};
    char* intervalRead{new char[34]{}};
    char* commentRead{new char[DEFAULT]{}};
    while (appointments.good())
    {
        bool executed{false};
        appointments.getline(nameRead, DEFAULT, '\n');
        appointments.getline(intervalRead, 34, '\n');
        allIntervals << intervalRead << '\n';
        appointments.getline(commentRead, DEFAULT, '\n');
        if (myStrcmp(name, nameRead) && myStrcmp(intervalString, intervalRead))
        {
            char answer[4];
            std::cout << "Would you like to change the name of the event?\n";
            std::cin.getline(answer, 4, '\n');
            if (myStrcmp(answer, "yes"))
            {
                std::cout << "Enter a new name: ";
                std::cin.getline(name, DEFAULT, '\n');
            }
            std::cout << "Would you like to change the time interval of the event?\n";
            std::cin.getline(answer, 4, '\n');
            TimeInterval current;
            current = intervalRead;
            if (myStrcmp(answer, "yes"))
            {
                Date newStartDate = current.getStartDate();
                Time newStartTime = current.getStartTime();
                Date newEndDate = current.getEndDate();
                Time newEndTime = current.getEndTime();
                std::cout << "Would you like to change the start date?\n";
                std::cin.getline(answer, 4, '\n');
                if (myStrcmp(answer, "yes"))
                {
                    std::cout << "Enter a new start date: ";
                    std::cin >> newStartDate;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the start time?\n";
                std::cin.getline(answer, 4, '\n');
                if (myStrcmp(answer, "yes"))
                {
                    std::cout << "Enter a new start time: ";
                    std::cin >> newStartTime;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the end date?\n";
                std::cin.getline(answer, 4, '\n');
                if (myStrcmp(answer, "yes"))
                {
                    std::cout << "Enter a new end date: ";
                    std::cin >> newEndDate;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the end time?\n";
                std::cin.getline(answer, 4, '\n');
                if (myStrcmp(answer, "yes"))
                {
                    std::cout << "Enter a new end time: \n";
                    std::cin >> newEndTime;
                    std::cin.ignore();
                }
                interval = TimeInterval(newStartDate, newStartTime, newEndDate, newEndTime);
            }
            std::cout << "Would you like to change the comment of the event?\n";
            std::cin.getline(answer, 4, '\n');
            myStrcpy(commentRead, comment);
            if (myStrcmp(answer, "yes"))
            {
                std::cout << "Enter a new comment: ";
                std::cin.getline(comment, DEFAULT, '\n');
            }
            changed << name << '\n' << interval << '\n' << comment << '\n';
            executed = true;
        }
        if ((!executed) && !(myStrcmp(nameRead, intervalRead) && myStrcmp(intervalRead, commentRead)))
        {
            changed << nameRead << '\n' << intervalRead << '\n' << commentRead << '\n'; //dali ne moje da se smesi s gornoto na red 221?
        }
    }
    delete[] nameRead;
    delete[] commentRead;
    delete[] name;
    delete[] comment;
    appointments.close();
    std::fstream intervals("intervals.txt", std::ios::out); //Файл с всички интервали
    intervals << allIntervals.str();
    while (intervals.good())
    {
        intervals.getline(intervalRead, 34, '\n');
        TimeInterval currentLine;
        currentLine = intervalRead;
        if (currentLine.isIn(interval))
        {
            std::cout << "The given interval is not free!";
            std::cout << "Reverting changes made to the interval...";
            interval = originalInterval;
        }
    }
    remove("intervals.txt");
    std::ofstream newAppointments("appointments.txt", std::ios::trunc); //Нов файл с направените промени
    newAppointments << changed.str();
    //не прави revert-ването на промените ако съвпадат????
}

void search()
{
    char* search{new char[DEFAULT]{}};
    std::cin.getline(search, DEFAULT, '\n');
    char* name{new char[DEFAULT]{}};
    char* interval{new char[34]};
    char* comment{new char[DEFAULT]};
    std::stringstream print;
    std::ifstream appointments{"appointments.txt", std::ios::in};
    while (appointments.good())
    {
        appointments.getline(name, DEFAULT, '\n');
        appointments.getline(interval, DEFAULT, '\n');
        appointments.getline(comment, DEFAULT, '\n');
        if (subStringCheck(search, name) || subStringCheck(search, comment))
        {
            if (!(name[0] == 0 && interval[0] == 0 && comment[0] == 0))
            {
                print << name << '\n' << interval << '\n' << comment << '\n';
            }
        }
    }
    delete[] search;
    delete[] name;
    delete[] interval;
    delete[] comment;
    std::cout << print.str();
}

void determineAction()
{
    char possibleActions[numberOfActions][9]{"Create", "Delete", "Schedule", "Change", "Search", "Busyness", "Free"};
    char action[9];
    std::cin.getline(action, 9, '\n');
    if (myStrcmp(action, possibleActions[0]))
    {
        create();
    }
    else if (myStrcmp(action, possibleActions[1]))
    {
        deleteEvent();
    }
    else if (myStrcmp(action, possibleActions[2]))
    {
        schedule();
    }
    else if (myStrcmp(action, possibleActions[3]))
    {
        change();
    }
    else if (myStrcmp(action, possibleActions[4]))
    {
        search();
    }
    /*else if(myStrcmp(action,possibleActions[5]))
    else if(myStrcmp(action,possibleActions[6]))
    */
}

