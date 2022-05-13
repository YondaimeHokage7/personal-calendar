#include "functions.hpp"

bool isLeap(int year)
{
    bool leapPrerequisite{year % 4 == 0};
    bool leapException{year % 100 == 0};
    bool leapExceptionOfTheException{year % 400 == 0};
    return leapPrerequisite && (!leapException || leapExceptionOfTheException);
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

bool strcmp(const char* string1,const char* string2)
{
    bool result{true};
    if (myStrlen(string1) != myStrlen(string2))
    {
        result = false;
    }
    for (int i{0}; string1[i] != '\0' && string2[i] != '\0' && result; i++)
    {
        if (string1[i] != string2[i])
        {
            result = false;
        }
    }
    return result;
}
