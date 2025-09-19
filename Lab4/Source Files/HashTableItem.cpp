#include "HashTableItem.h"

HashTableItem::HashTableItem(std::string key, std::string value, HashTableItem* next)
	: Key(key), Value(value), Next(next) {}
HashTableItem::HashTableItem(std::string key, std::string value)
	: Key(key), Value(value) {}