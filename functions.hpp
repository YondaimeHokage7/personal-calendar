#ifndef PERSONAL_CALENDAR_FUNCTIONS_HPP
#define PERSONAL_CALENDAR_FUNCTIONS_HPP

#include <sstream>
#include "date.hpp"
#include "timeInterval.hpp"
#include "appointment.hpp"

//! Функция проверяваща за поддума на друга дума
bool subStringCheck(const char* substring, const char* string);

//! Функция сравняваща два интервала
bool compareIntervals(TimeInterval, TimeInterval);

//! Функция брояща символите в низ
int myStrlen(const char* string);

//! Функцция копираща низ в друг низ
void myStrcpy(const char* source, char* destination);

//! Функция сравняваща два низа
bool myStrcmp(const char* string1, const char* string2);


#endif //PERSONAL_CALENDAR_FUNCTIONS_HPP
