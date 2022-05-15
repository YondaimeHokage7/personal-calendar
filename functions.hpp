#ifndef PERSONAL_CALENDAR_FUNCTIONS_HPP
#define PERSONAL_CALENDAR_FUNCTIONS_HPP

#include <sstream>
#include "date.hpp"
#include "timeInterval.hpp"
#include "appointment.hpp"

void mySwap(Appointment[], int index1, int index2);

bool subStringCheck(const char* substring, const char* string);

bool compareIntervals(TimeInterval, TimeInterval);

int myStrlen(const char* string);

void myStrcpy(const char* source, char* destination);

bool myStrcmp(const char* string1, const char* string2);


#endif //PERSONAL_CALENDAR_FUNCTIONS_HPP
