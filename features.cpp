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
} //NE PIPAI!!!

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
            if (notEmpty &&
                !(myStrcmp(appointment.getName(), read.getName()) && compareIntervals(appointment.getInterval(), read.getInterval()) && myStrcmp(appointment.getComment(), read.getComment())))
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
} //NE PIPAI!!!

void schedule()
{
    std::cout << "Date: \n";
    Date date;
    std::cin >> date;
    std::ifstream fi("appointments.txt", std::ios::in);
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
} // NE PIPAI!!!!!! //samo trqbva da sa v hronologichen red

void change()
{
    std::cout << "Appointment: \n";
    Appointment userInput;
    std::cin >> userInput;
    std::ifstream appointments("appointments.txt", std::ios::in);
    Appointment changed;
    Appointment fileInput;
    std::stringstream changedAppointments;
    while (appointments.good() && appointments.is_open())
    {
        appointments >> fileInput;
        changed = fileInput;
        if (myStrcmp(userInput.getName(), fileInput.getName()) && (userInput.getInterval() == fileInput.getInterval()) && myStrcmp(userInput.getComment(), fileInput.getComment()))
        {
            char answer[4]{};
            std::cout << "Would you like to change the name of the event?\n";
            std::cin.getline(answer, 4, '\n');
            if (myStrcmp(answer, "yes"))
            {
                char* name{new char[DEFAULT]{}};
                std::cout << "Enter a new name: ";
                std::cin.getline(name, DEFAULT, '\n');
                changed.setName(name);
                delete[] name;
            }
            std::cout << "Would you like to change the time interval of the event?\n";
            std::cin.getline(answer, 4, '\n');
            if (myStrcmp(answer, "yes"))
            {
                Date newStartDate = changed.getInterval().getStartDate();
                Time newStartTime = changed.getInterval().getStartTime();
                Date newEndDate = changed.getInterval().getEndDate();
                Time newEndTime = changed.getInterval().getEndTime();
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
                changed.setInterval(TimeInterval(newStartDate, newStartTime, newEndDate, newEndTime));
            }
            std::cout << "Would you like to change the comment of the event?\n";
            std::cin.getline(answer, 4, '\n');
            if (myStrcmp(answer, "yes"))
            {
                char* comment{new char[DEFAULT]{}};
                std::cout << "Enter a new comment: ";
                std::cin.getline(comment, DEFAULT, '\n');
                changed.setComment(comment);
                delete[] comment;
            }
        }
        if (!(myStrcmp(fileInput.getName(), fileInput.getComment())))
        {
            changedAppointments << changed << '\n';
        }
    }
    appointments.close();
    //std::ofstream newAppointments("appointments.txt", std::ios::trunc); //Нов файл с направените промени
    std::cout << changedAppointments.str();
    //не прави revert-ването на промените ако съвпадат????
} //ne moga

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

