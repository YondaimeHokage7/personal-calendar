#ifndef PERSONAL_CALENDAR_FEATURES_HPP
#define PERSONAL_CALENDAR_FEATURES_HPP

const int numberOfActions{7};

//! Извежда инструкциите в началото
void printInstructions();

//! Преценява и пуска функцията, която трябва
void determineAction();

//! Съзадава ангажимент
void create();

//! Изтрива ангажимент
void deleteEvent();

#endif //PERSONAL_CALENDAR_FEATURES_HPP
