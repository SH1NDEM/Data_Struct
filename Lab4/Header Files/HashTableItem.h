#pragma once
#include <string>

//! \brief ���-�������
struct HashTableItem
{
	//! \brief ���� ��� ��������.
	std::string Key;

	//! \brief �������� ��������.
	std::string Value;

	//! \brief ������ �� ��������� ������� � �������.
	HashTableItem* Next = nullptr;

	//! \brief ����������� ��� ��������.
	//! \param key ���� ��� ��������.
	//! \param value �������� ��� ��������.
	//! \param next ��������� �������.
	HashTableItem(std::string key, std::string value, HashTableItem* next);

	//! \brief ����������� ��� ��������.
	//! \param key ���� ��� ��������.
	//! \param value �������� ��� ��������..
	HashTableItem(std::string key, std::string value);
};