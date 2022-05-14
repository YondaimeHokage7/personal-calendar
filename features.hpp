#ifndef PERSONAL_CALENDAR_FEATURES_HPP
#define PERSONAL_CALENDAR_FEATURES_HPP
#include <cstddef>

const int numberOfActions{7};
const size_t DEFAULT{1000};

//! Извежда инструкциите в началото
void printInstructions();

//! Преценява и пуска функцията, която трябва
void determineAction();

//! Съзадава ангажимент
void create();

//! Изтрива ангажимент
void deleteEvent();

//! Показва ангажиментите за въведена дата
void schedule();

//! Сменя име/начало/край/коментар на въведен ангажимент
void change();

//! Търси даден string в имена и коемтнари
void search();

#endif //PERSONAL_CALENDAR_FEATURES_HPP
