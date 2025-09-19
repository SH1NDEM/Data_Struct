#pragma once
#include <string>

//! \brief Хэш-таблица
struct HashTableItem
{
	//! \brief Ключ для элемента.
	std::string Key;

	//! \brief Значение элемента.
	std::string Value;

	//! \brief Ссылка на следующий элемент в цепочке.
	HashTableItem* Next = nullptr;

	//! \brief Конструктор для элемента.
	//! \param key Ключ для элемента.
	//! \param value Значение для элемента.
	//! \param next Следующий элемент.
	HashTableItem(std::string key, std::string value, HashTableItem* next);

	//! \brief Конструктор для элемента.
	//! \param key Ключ для элемента.
	//! \param value Значение для элемента..
	HashTableItem(std::string key, std::string value);
};