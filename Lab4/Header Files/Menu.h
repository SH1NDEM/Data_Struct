#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Dictionary.h"

using namespace std;

//! \brief Функция для управления меню
void MenuController();

//! \brief Функция для отображения хэш-таблицы
//! \param dictionary Указатель на объект Dictionary, содержащий хэш-таблицу
void ShowHashTable(Dictionary* dictionary);

//! \brief Функция для отображения словаря
//! \param dictionary Указатель на объект Dictionary, который нужно отобразить
void ShowDictionary(Dictionary* dictionary);

//! \brief Функция для получения имени типа
//! \param letter Символ, представляющий тип
//! \return Имя типа в виде строки
string GetTypeName(const char* letter);

//! \brief Шаблон функции для проверки корректного ввода
//! \tparam Type Тип данных, который ожидается на входе
//! \return Корректно введенное значение типа Type
template <typename Type>
Type ValidInput();

//! \brief Функция для очистки терминала
void ClearTerminal();

#endif // MENU_H
