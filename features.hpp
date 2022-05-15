#ifndef PERSONAL_CALENDAR_FEATURES_HPP
#define PERSONAL_CALENDAR_FEATURES_HPP
#include <cstddef>

//! Брой възможни операции
const int numberOfActions{5};

//! Големина на низ по подразбиране
const size_t DEFAULT{1000};

//! Функция извеждаща инструкциите в началото
void printInstructions();

//! Функция пускаща действието, което трябва
void determineAction();

//! Функция съзадаваща ангажимент
void create();

//! Функция изтриваща ангажимент
void deleteEvent();

//! Функция показваща ангажиментите за въведена дата
void schedule();

//! Функция сменяща име/начало/край/коментар на въведен ангажимент
void change();

//! Функция търсеща даден низ в имена и коментари
void search();

#endif //PERSONAL_CALENDAR_FEATURES_HPP
