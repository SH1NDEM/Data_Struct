#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Dictionary.h"

using namespace std;

//! \brief ������� ��� ���������� ����
void MenuController();

//! \brief ������� ��� ����������� ���-�������
//! \param dictionary ��������� �� ������ Dictionary, ���������� ���-�������
void ShowHashTable(Dictionary* dictionary);

//! \brief ������� ��� ����������� �������
//! \param dictionary ��������� �� ������ Dictionary, ������� ����� ����������
void ShowDictionary(Dictionary* dictionary);

//! \brief ������� ��� ��������� ����� ����
//! \param letter ������, �������������� ���
//! \return ��� ���� � ���� ������
string GetTypeName(const char* letter);

//! \brief ������ ������� ��� �������� ����������� �����
//! \tparam Type ��� ������, ������� ��������� �� �����
//! \return ��������� ��������� �������� ���� Type
template <typename Type>
Type ValidInput();

//! \brief ������� ��� ������� ���������
void ClearTerminal();

#endif // MENU_H
