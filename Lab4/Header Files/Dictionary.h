#pragma once

#include "HashTable.h"

//! \brief ����� �������
class Dictionary
{
private:
    //! \brief ���-�������
    HashTable* _hashTable;

public:
    //! \brief ����������� �������
    Dictionary();

    //! \brief ���������� �������
    ~Dictionary();

    //! \brief ���������� � ������� ����-��������
    //! \param key ����, �� �������� ����� ��������� ��������
    //! \param value ��������, ������� ����� ��������� ��� ��������� ������
    void Add(const string& key, const string& value);

    //! \brief �������� �� ������� ����-��������
    //! \param key ����, �� �������� ����� ����������� ��������
    //! \return ������ �������� (����� ��� �������)
    void Delete(const string& key);

    //! \brief ����� �������� �� �����
    //! \param key ����, �� �������� ����� ��������� ����� ��������
    //! \return ��������, ��������������� ���������� �����; ������ ������, ���� ���� �� ������
    string Search(const string& key);

    //! \brief ����� ���-�������
    //! \return ��������� �� ���-�������
    HashTable* GetHashTable();
};