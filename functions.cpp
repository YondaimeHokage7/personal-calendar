#include "functions.hpp"

bool subStringCheck(const char* substring, const char* string)
{
    if (myStrlen(substring) > myStrlen(string))
    {
        return false;
    }
    int k{0};
    bool found{true};
    for (int i{0}; string[i] != '\0'; i++)
    {
        if (substring[k] == string[i])
        {
            for (int j{i}; substring[k] != '\0' && string[j] != '\0' && found; j++, k++)
            {
                if (substring[k] != string[j])
                {
                    found = false;
                }
                else if (substring[k + 1] == '\0')
                {
                    return true;
                }
                else if (string[j + 1] == '\0' && substring[k + 1] != '\0')
                {
                    return false;
                }
            }
            k = 0;
            found = true;
        }
    }
    return false;
}

bool compareIntervals(TimeInterval interval1, TimeInterval interval2)
{
    return interval1.getStartDate() == interval2.getStartDate() && interval1.getStartTime() == interval2.getStartTime() &&
           interval1.getEndDate() == interval2.getEndDate() && interval1.getEndTime() == interval2.getEndTime();
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

void myStrcpy(const char* source, char* destination)
{
    for (int i{0}; source[i] != '\0'; i++)
    {
        destination[i] = source[i];
    }
}

bool myStrcmp(const char* string1, const char* string2)
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
