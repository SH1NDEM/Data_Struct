#pragma once

#include "HashTableItem.h"
#include <random>
#include <ctime>
#include <string>

using namespace std;

//! \brief ����� ���-�������
class HashTable
{
    //! \brief ����������� �������� ���-�������
private:
    static const int MinCapacity = 4; 

    //! \brief ��������
    int _capacity;

    //! \brief �����
    int _length;

    //! \brief ������� �������
    int* _pearsonTable;

    //! \brief ������ �������
    HashTableItem** _data;

    //! \brief �������� ����� ������� �������
    int* MakePearsonTable();

    //! \brief ����� ���-���
    //! \param key ����
    //! \return ���-���
    int GetHashCode(string key);

    //! \brief ���������������
    //! \param capacity ����� �������� ���-�������
    void Rehashig(int capacity);

    //! \brief ���������� ��������
    //! \param item ����������� �������
    //! \param key ����
    //! \param value ��������
    HashTableItem* ResolveCollision(HashTableItem* item, string key, string value);

    //! \brief �������� ������� � ������ � ���������� �������
    //! \param item ������� ������
    //! \param key ����
    //! \param value ���������� ������� ������
    HashTableItem* AddRightOrder(HashTableItem* item, string key, string value);

    //! \brief ������� �������
    //! \param item ������� ������
    //! \param key ���� ���������� ��������
    //! \return ���������� ������� ������
    HashTableItem* Delete(HashTableItem* item, string key);

public:
    //! \brief �����������
    //! \param capacity �������� ���-�������
    HashTable(int capacity = MinCapacity);

    //! \brief ����������
    ~HashTable();

    //! \brief ���������� ����-�������� � �������
    //! \param key ����
    //! \param value ��������
    void Add(string key, string value);

    //! \brief �������� ����-�������� �� �������
    //! \param key ����
    //! \return ������ ��������
    void Delete(string key);

    //! \brief ����� �������� �� �����
    //! \param key ����
    //! \return ������ ������� ���-�������
    HashTableItem* Search(string key, int hashCode = -1);

    //! \brief ������ ������ ���-������� �� ������
    //! \return ������ ���-�������
    HashTableItem** GetData();

    //! \brief ������ �������� ���-�������
    //! \return ��������
    int GetCapacity();
};

