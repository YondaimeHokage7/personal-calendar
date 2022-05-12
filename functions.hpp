#ifndef PERSONAL_CALENDAR_FUNCTIONS_HPP
#define PERSONAL_CALENDAR_FUNCTIONS_HPP

#include <sstream>
#include "date.hpp"

bool isLeap(int year);

void ensureValidDate(Date&);

int myStrlen(const char* string);

void strcpy(const char* source, char* destination);

bool strcmp(char* action, char* possibleAction);

void putInStringStream(char* string, std::stringstream& saved);


#endif //PERSONAL_CALENDAR_FUNCTIONS_HPP
