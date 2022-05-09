#include <iostream>
#include <fstream>
#include <sstream>
#include "appointment.hpp"
#include "functions.hpp"
#include "timeInterval.hpp"

const int numberOfActions{7};

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
    fo << appointment;
}

void putInStringStream(char* string, std::stringstream& saved)
{
    for (int i{0}; string[i] != '\0'; i++)
    {
        saved << string[i];
    }
}

void deleteEvent()
{
    char* userInput{new char[defaultNameSize]};
    std::cout << "Eevent name: ";
    std::cin.getline(userInput, defaultNameSize, '\n');
    std::cout << "Enter time interval: ";
    TimeInterval interval;
    std::cin >> interval;
    std::fstream f("appointments.txt", std::ios::out | std::ios::in);
    std::stringstream saved;
    std::stringstream deleted;
    char* lineRead{new char[defaultCommentSize]};
    for (int i{0}; !f.eof(); i++)
    {
        f.getline(lineRead, defaultCommentSize, '\n');
        if (strcmp(lineRead, userInput))
        {
            putInStringStream(lineRead, deleted); //слага името на event в deleted
            f.getline(lineRead, defaultCommentSize);
            putInStringStream(lineRead, deleted); //слага интервала на event в deleted
            f.getline(lineRead, defaultCommentSize);
            putInStringStream(lineRead, deleted); //слага коментара на event в deleted
            f.getline(lineRead, defaultCommentSize);
            putInStringStream(lineRead, deleted); // слага новия ред в deleted
            deleted.flush();
        }
        else
        {
            putInStringStream(lineRead, saved);
            char newline[1]{'\n'};
            putInStringStream(newline, saved);
        }
    }
    delete[] userInput;
    delete[] lineRead;
    std::ofstream ofs("appointments.txt", std::ios::trunc);
    ofs << saved.str();
}

int main()
{
    std::cout << "What would you like to do?\n";
    std::cout << "\"Create\" to create an event\n";
    std::cout << "\"Delete\" to delete an event\n";
    std::cout << "\"Schedule\" to see a chronological schedule for a day\n";
    std::cout << "\"Change\" to change an event\n";
    std::cout << "\"Search\" to search for an event\n";
    std::cout << "\"Busyness\" presents the most busy days\n";
    std::cout << "\"Free\" searches for a free time in a given interval\n";
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
    /*else if(strcmp(action,possibleActions[2]))
    else if(strcmp(action,possibleActions[3]))
    else if(strcmp(action,possibleActions[4]))
    else if(strcmp(action,possibleActions[5]))
    else if(strcmp(action,possibleActions[6]))
    else if(strcmp(action,possibleActions[7]))
    */
    return 0;
}