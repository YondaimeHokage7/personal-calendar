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
    char* placeHolder{new char[DEFAULT]};
    Appointment appointment;
    std::cout << "Event name: ";
    std::cin.getline(placeHolder, DEFAULT, '\n');
    appointment.setName(placeHolder);
    delete[] placeHolder;
    placeHolder = new char[DEFAULT];
    std::cout << "Comment: ";
    std::cin.getline(placeHolder, DEFAULT, '\n');
    appointment.setComment(placeHolder);
    delete[] placeHolder;
    std::cout << "Interval: ";
    TimeInterval interval;
    std::cin >> interval;
    appointment.setStartDate(interval.getStartDate().getDay(), interval.getStartDate().getMonth(), interval.getStartDate().getYear());
    appointment.setStartTime(interval.getStartTime().getHours(), interval.getStartTime().getMinutes());
    appointment.setEndDate(interval.getEndDate().getDay(), interval.getEndDate().getMonth(), interval.getEndDate().getYear());
    appointment.setEndTime(interval.getEndTime().getHours(), interval.getEndTime().getMinutes());
    std::ofstream fo("appointments.txt", std::ios::app);
    if (fo.is_open())
    {
        fo << appointment;
    }
    else
    {
        std::cout << "Error!";
    }
}

void deleteEvent()
{
    std::cout << "Eevent name: ";
    char* name{new char[DEFAULT]};
    std::cin.getline(name, DEFAULT, '\n');
    std::cout << "Enter time interval: ";
    char* intervalString{new char[34]};
    TimeInterval interval;
    std::cin >> interval;
    interval = intervalString;
    std::fstream f("appointments.txt", std::ios::out | std::ios::in);
    if (f.is_open())
    {
        std::stringstream saved;
        std::stringstream deleted;
        char* nameRead{new char[DEFAULT]};
        char* intervalRead{new char[34]};
        char* commentRead{new char[DEFAULT]};
        while (f.good())
        {
            f.getline(nameRead, DEFAULT, '\n');
            f.getline(intervalRead, 34, '\n');
            f.getline(commentRead, DEFAULT, '\n');
            if (strcmp(nameRead, name) && strcmp(intervalRead, intervalString))
            {
                deleted << nameRead << intervalRead << commentRead;
            }
            else
            {
                if (!(nameRead[0] == 0 && intervalRead[0] == 0 && commentRead[0] == 0))
                {
                    saved << nameRead << '\n' << intervalRead << '\n' << commentRead << '\n';
                }
            }
        }
        delete[] name;
        delete[] intervalString;
        delete[] nameRead;
        delete[] intervalRead;
        delete[] commentRead;
        std::ofstream ofs("appointments.txt", std::ios::trunc);
        ofs << saved.str();
    }
    else
    {
        std::cout << "Error!";
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
            if (!(strcmp(name, intervalStr) && strcmp(intervalStr, comment)))
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
        if (strcmp(name, nameRead) && strcmp(intervalString, intervalRead))
        {
            char answer[4];
            std::cout << "Would you like to change the name of the event?\n";
            std::cin.getline(answer, 4, '\n');
            if (strcmp(answer, "yes"))
            {
                std::cout << "Enter a new name: ";
                std::cin.getline(name, DEFAULT, '\n');
            }
            std::cout << "Would you like to change the time interval of the event?\n";
            std::cin.getline(answer, 4, '\n');
            TimeInterval current;
            current = intervalRead;
            if (strcmp(answer, "yes"))
            {
                Date newStartDate = current.getStartDate();
                Time newStartTime = current.getStartTime();
                Date newEndDate = current.getEndDate();
                Time newEndTime = current.getEndTime();
                std::cout << "Would you like to change the start date?\n";
                std::cin.getline(answer, 4, '\n');
                if (strcmp(answer, "yes"))
                {
                    std::cout << "Enter a new start date: ";
                    std::cin >> newStartDate;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the start time?\n";
                std::cin.getline(answer, 4, '\n');
                if (strcmp(answer, "yes"))
                {
                    std::cout << "Enter a new start time: ";
                    std::cin >> newStartTime;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the end date?\n";
                std::cin.getline(answer, 4, '\n');
                if (strcmp(answer, "yes"))
                {
                    std::cout << "Enter a new end date: ";
                    std::cin >> newEndDate;
                    std::cin.ignore();
                }
                std::cout << "Would you like to change the end time?\n";
                std::cin.getline(answer, 4, '\n');
                if (strcmp(answer, "yes"))
                {
                    std::cout << "Enter a new end time: \n";
                    std::cin >> newEndTime;
                    std::cin.ignore();
                }
                interval = TimeInterval(newStartDate, newStartTime, newEndDate, newEndTime);
            }
            std::cout << "Would you like to change the comment of the event?\n";
            std::cin.getline(answer, 4, '\n');
            strcpy(commentRead, comment);
            if (strcmp(answer, "yes"))
            {
                std::cout << "Enter a new comment: ";
                std::cin.getline(comment, DEFAULT, '\n');
            }
            changed << name << '\n' << interval << '\n' << comment << '\n';
            executed = true;
        }
        if ((!executed) && !(strcmp(nameRead, intervalRead) && strcmp(intervalRead, commentRead)))
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
    if (strcmp(action, possibleActions[0]))
    {
        create();
    }
    else if (strcmp(action, possibleActions[1]))
    {
        deleteEvent();
    }
    else if (strcmp(action, possibleActions[2]))
    {
        schedule();
    }
    else if (strcmp(action, possibleActions[3]))
    {
        change();
    }
    else if (strcmp(action, possibleActions[4]))
    {
        search();
    }
    /*else if(strcmp(action,possibleActions[5]))
    else if(strcmp(action,possibleActions[6]))
    */
}

