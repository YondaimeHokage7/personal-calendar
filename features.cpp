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
        std::cerr << "Error! File not found!";
    }
}

void deleteEvent()
{
    std::ifstream f("appointments.txt", std::ios::in);
    if (f.is_open())
    {
        std::cout << "Appointment: \n";
        Appointment appointment;
        std::cin >> appointment;
        Appointment read;
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
        std::cerr << "Error! File not found!";
    }
}

void schedule()
{
    std::ifstream fi("appointments.txt", std::ios::in);
    if (fi.is_open())
    {
        std::cout << "Date: \n";
        Date date;
        std::cin >> date;
        std::stringstream toBePrinted;
        while (fi.good())
        {
            Appointment appointment;
            fi >> appointment;
            if (date.isInAnInterval(appointment.getInterval().getStartDate(), appointment.getInterval().getEndDate()))
            {
                if (!(myStrcmp(appointment.getName(), appointment.getComment())))
                {
                    toBePrinted << appointment.getName() << '\n' << appointment.getInterval() << '\n' << appointment.getComment() << '\n';
                }
            }
        }
        fi.close();
        std::cout << toBePrinted.str();
    }
    else
    {
        std::cerr << "Error! File not found!";
    }
}

void change()
{
    std::ifstream appointments("appointments.txt", std::ios::in);
    if(appointments.is_open())
    {
        char* name{new char[DEFAULT]{}};
        char* intervalString{new char[34]{}};
        char* comment{new char[DEFAULT]{}};
        std::stringstream changed;
        std::stringstream allIntervals;
        TimeInterval interval;
        std::cout << "Eevent name: ";
        std::cin.getline(name, DEFAULT, '\n');
        std::cout << "Enter time interval: ";
        std::cin.getline(intervalString, 34, '\n');
        interval = intervalString;
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
                changed << nameRead << '\n' << intervalRead << '\n' << commentRead << '\n';
            }
        }
        delete[] nameRead;
        delete[] commentRead;
        delete[] name;
        delete[] comment;
        appointments.close();
        std::ofstream newAppointments("appointments.txt", std::ios::trunc); //Нов файл с направените промени
        newAppointments << changed.str();
    }
    else
    {
        std::cerr << "Error! File not found!";
    }
}

void search()
{
    std::ifstream appointments{"appointments.txt", std::ios::in};
    if(appointments.is_open())
    {
        std::cout << "String: ";
        char* search{new char[DEFAULT]{}};
        std::cin.getline(search, DEFAULT, '\n');
        std::stringstream print;
        Appointment fileApp;
        while (appointments.good())
        {
            appointments >> fileApp;
            if (subStringCheck(search, fileApp.getName()) || subStringCheck(search, fileApp.getComment()))
            {
                if (!(myStrcmp(fileApp.getName(), fileApp.getComment())))
                {
                    print << fileApp.getName() << '\n' << fileApp.getInterval() << '\n' << fileApp.getComment() << '\n';
                }
            }
        }
        delete[] search;
        std::cout << print.str();
    }
    else
    {
        std::cerr << "Error! File not found!";
    }
}

void determineAction()
{
    char possibleActions[numberOfActions][9]{"Create", "Delete", "Schedule", "Change", "Search"};
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
}

