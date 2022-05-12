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
    char* placeHolder{new char[defaultNameSize]};
    Appointment appointment;
    std::cout << "Event name: ";
    std::cin.getline(placeHolder, defaultNameSize, '\n');
    appointment.setName(placeHolder);
    delete[] placeHolder;
    placeHolder = new char[defaultCommentSize];
    std::cout << "Comment: ";
    std::cin.getline(placeHolder, defaultCommentSize, '\n');
    appointment.setComment(placeHolder);
    delete[] placeHolder;
    int year1, year2;
    unsigned month1, month2, day1, day2, hours1, hours2, minutes1, minutes2;
    std::cout << "Interval: ";
    char c;
    std::cin >> day1 >> c >> month1 >> c >> year1 >> hours1 >> c >> minutes1 >> day2 >> c >> month2 >> c >> year2 >> hours2 >> c >> minutes2;
    std::cin.ignore();
    appointment.setStartDate(day1, month1, year1);
    appointment.setStartTime(hours1, minutes1);
    appointment.setEndDate(day2, month2, year2);
    appointment.setEndTime(hours2, minutes2);
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
    char* name{new char[defaultNameSize]};
    std::cin.getline(name, defaultNameSize, '\n');
    std::cout << "Enter time interval: ";
    char* interval{new char[34]};
    std::cin.getline(interval, 34, '\n');
    std::stringstream intervalStream;
    intervalStream << interval;
    //!!!intervalStream >> interval da se proveri za pravilnost
    std::fstream f("appointments.txt", std::ios::out | std::ios::in);
    if (f.is_open())
    {
        std::stringstream saved;
        std::stringstream deleted;
        char* nameRead{new char[defaultNameSize]};
        char* intervalRead{new char[34]};
        char* commentRead{new char[defaultCommentSize]};
        while (f.good())
        {
            f.getline(nameRead, defaultCommentSize, '\n');
            f.getline(intervalRead, 34, '\n');
            f.getline(commentRead, defaultCommentSize, '\n');
            if (strcmp(nameRead, name) && strcmp(intervalRead, interval))
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
        delete[] interval;
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
    std::stringstream toBePrinted;
    std::cout << "Enter a date: ";
    Date date;
    std::cin >> date;
    std::ifstream fi("appointments.txt", std::ios::in);
    TimeInterval interval;
    std::stringstream intervals;
    std::stringstream trash;
    char* name{new char[defaultNameSize]};
    char* intervalStr{new char[34]};
    char* comment{new char[defaultCommentSize]};
    while (fi.good())
    {
        fi.getline(name, defaultNameSize, '\n');
        fi.getline(intervalStr, 34, '\n');
        intervals << intervalStr;
        intervals >> interval;
        fi.getline(comment, defaultCommentSize, '\n');
        if (date.isInAnInterval(interval.getStartDate(), interval.getEndDate()))
        {
            if (!(strcmp(name, intervalStr) && strcmp(intervalStr, comment)))
            {
                toBePrinted << name << '\n' << intervalStr << '\n' << comment << '\n';
            }
        }
        intervals.clear();
    }
    delete[] name;
    delete[] intervalStr;
    delete[] comment;
    std::cout << toBePrinted.str();
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
    /*else if(strcmp(action,possibleActions[3]))
    else if(strcmp(action,possibleActions[4]))
    else if(strcmp(action,possibleActions[5]))
    else if(strcmp(action,possibleActions[6]))
    else if(strcmp(action,possibleActions[7]))
    */
}

