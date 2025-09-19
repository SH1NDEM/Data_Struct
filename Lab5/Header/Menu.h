#pragma once
#include <iostream>
#include "Treap.h"
#include "BinaryTree.h"

using namespace std;

//! \brief Вывод бинарного дерева в консоль с заданным отступом.
//! \param root Корневой узел бинарного дерева.
//! \param space Текущий уровень отступа.
//! \param levelIndent Шаг увеличения отступа для каждого уровня.
void PrintBinaryTree(BinaryTreeNode* root, int space, int levelIndent);

//! \brief Вывод дерева Treap в консоль с заданным отступом.
//! \param current Текущий узел дерева Treap.
//! \param space Текущий уровень отступа.
//! \param levelIndent Шаг увеличения отступа для каждого уровня.
void PrintTreap(TreapNode* current, int space, int levelIndent);

//! \brief Отображение главного меню программы.
void ShowMenu();

//! \brief Получение целочисленного ввода от пользователя.
//! \return Целочисленное значение, введенное пользователем.
int GetIntegerInput();

//! \brief Очистка некорректного ввода в потоке.
void ClearInput();

//! \brief Отображение меню для работы с деревом Treap.
void ShowTreapMenu();

//! \brief Отображение меню для работы с бинарным деревом.
void ShowBinaryTreeMenu();

//! \brief Очистка терминала для удобства отображения данных.
void ClearTerminal();
