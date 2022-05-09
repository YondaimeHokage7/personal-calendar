#include "functions.hpp"

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
