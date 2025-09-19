#pragma once

#include "HashTableItem.h"
#include <random>
#include <ctime>
#include <string>

using namespace std;

//! \brief Класс хеш-таблицы
class HashTable
{
    //! \brief Минимальная мощность хеш-таблицы
private:
    static const int MinCapacity = 4; 

    //! \brief Мощность
    int _capacity;

    //! \brief Длина
    int _length;

    //! \brief Таблицы Пирсона
    int* _pearsonTable;

    //! \brief Данные таблицы
    HashTableItem** _data;

    //! \brief Создание новой таблицы Пирсона
    int* MakePearsonTable();

    //! \brief Найти хеш-код
    //! \param key Ключ
    //! \return Хеш-код
    int GetHashCode(string key);

    //! \brief Перехеширование
    //! \param capacity Новая мощность хеш-таблицы
    void Rehashig(int capacity);

    //! \brief Разрешение коллизии
    //! \param item Конфликтный элемент
    //! \param key Ключ
    //! \param value Значение
    HashTableItem* ResolveCollision(HashTableItem* item, string key, string value);

    //! \brief Добавить элемент в список в правильном порядке
    //! \param item Элемент списка
    //! \param key Ключ
    //! \param value Измененный элемент списка
    HashTableItem* AddRightOrder(HashTableItem* item, string key, string value);

    //! \brief Удалить элемент
    //! \param item Элемент списка
    //! \param key Ключ удаляемого элемента
    //! \return Измененный элемент списка
    HashTableItem* Delete(HashTableItem* item, string key);

public:
    //! \brief Конструктор
    //! \param capacity Мощность хеш-таблицы
    HashTable(int capacity = MinCapacity);

    //! \brief Деструктор
    ~HashTable();

    //! \brief Добавление ключ-значения в таблицу
    //! \param key Ключ
    //! \param value Значение
    void Add(string key, string value);

    //! \brief Удаление ключ-значения из таблицы
    //! \param key Ключ
    //! \return Статус удаления
    void Delete(string key);

    //! \brief Поиск значения по ключу
    //! \param key Ключ
    //! \return Нужный элемент хеш-таблицы
    HashTableItem* Search(string key, int hashCode = -1);

    //! \brief Взятие данных хеш-таблицы из класса
    //! \return Данные хеш-таблицы
    HashTableItem** GetData();

    //! \brief Взятие мощности хеш-таблицы
    //! \return Мощность
    int GetCapacity();
};

