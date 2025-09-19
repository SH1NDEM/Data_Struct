#pragma once

#include "HashTable.h"

//! \brief Класс словаря
class Dictionary
{
private:
    //! \brief Хеш-таблица
    HashTable* _hashTable;

public:
    //! \brief Конструктор словаря
    Dictionary();

    //! \brief Деструктор словаря
    ~Dictionary();

    //! \brief Добавление в словарь ключ-значения
    //! \param key Ключ, по которому будет добавлено значение
    //! \param value Значение, которое будет добавлено под указанным ключом
    void Add(const string& key, const string& value);

    //! \brief Удаление из словаря ключ-значения
    //! \param key Ключ, по которому будет произведено удаление
    //! \return Статус удаления (успех или неудача)
    void Delete(const string& key);

    //! \brief Поиск значения по ключу
    //! \param key Ключ, по которому будет произведён поиск значения
    //! \return Значение, соответствующее указанному ключу; пустая строка, если ключ не найден
    string Search(const string& key);

    //! \brief Взять хэш-таблицу
    //! \return Указатель на хэш-таблицу
    HashTable* GetHashTable();
};