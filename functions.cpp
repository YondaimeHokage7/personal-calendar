#include "functions.hpp"

bool isLeap(int year)
{
    bool leapPrerequisite{year % 4 == 0};
    bool leapException{year % 100 == 0};
    bool leapExceptionOfTheException{year % 400 == 0};
    return leapPrerequisite && (!leapException || leapExceptionOfTheException);
}

void ensureValidDate(Date& date)
{
    while (date.getMonth() < 1 || date.getMonth() > 12)
    {
        std::cout << "Invalid month!\n";
        std::cout << "Enter a new date!";
        std::cin >> date;
    }
    while (date.getDay() < 1 || date.getDay() > 31)
    {
        std::cout << "Invalid day!\n";
        std::cout << "Enter a new date!";
        std::cin >> date;
    }
    while (date.getDay() > 30 && date.getMonth() == 4 || date.getMonth() == 6 || date.getMonth() == 9 || date.getMonth() == 11)
    {
        std::cout << "Invalid day!";
        std::cout << "Enter a new date!";
        std::cin >> date;
    }
    while (date.getDay() > 28 && !isLeap(date.getYear()) || date.getDay() > 29 && isLeap(date.getYear()))
    {
        std::cout << "Invalid day!";
        std::cout << "Enter a new date!";
        std::cin >> date;
    }
}

int myStrlen(const char* string)
{
    int counter{0};
    for (int i{0}; string[i] != '\0'; i++)
    {
        counter++;
    }
    return counter + 1;
}

void strcpy(const char* source, char* destination)
{
    for (int i{0}; source[i] != '\0'; i++)
    {
        destination[i] = source[i];
    }
}

bool strcmp(char* action, char* possibleAction)
{
    bool result{true};
    if (myStrlen(action) != myStrlen(possibleAction))
    {
        result = false;
    }
    for (int i{0}; action[i] != '\0' && possibleAction[i] != '\0' && result; i++)
    {
        if (action[i] != possibleAction[i])
        {
            result = false;
        }
    }
    return result;
}

void putInStringStream(char* string, std::stringstream& saved)
{
    for (int i{0}; string[i] != '\0'; i++)
    {
        saved << string[i];
    }
}

