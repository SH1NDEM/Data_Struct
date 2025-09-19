#pragma once
#include "BinaryTreeNode.h"
#include <iostream>

//! \brief Класс для представления бинарного дерева.
class BinaryTree
{
private:
	//! \brief Указатель на корневой узел дерева.
	BinaryTreeNode* _root;

	//! \brief Рекурсивное добавление значения в дерево.
	//! \param node Узел, в который добавляется значение.
	//! \param value Значение, которое нужно добавить.
	void Add(BinaryTreeNode*& node, int value);

	//! \brief Рекурсивный поиск узла с заданным значением.
	//! \param node Узел, с которого начинается поиск.
	//! \param value Значение для поиска.
	//! \return Указатель на найденный узел или nullptr, если значение не найдено.
	BinaryTreeNode* Search(BinaryTreeNode* node, int value);

	//! \brief Удаление узла с заданным значением.
	//! \param node Узел, в котором выполняется удаление.
	//! \param value Значение для удаления.
	//! \return Указатель на новый корневой узел поддерева.
	BinaryTreeNode* RemoveNode(BinaryTreeNode* node, int value);

	//! \brief Поиск узла с минимальным значением.
	//! \param node Узел, с которого начинается поиск.
	//! \return Указатель на узел с минимальным значением.
	BinaryTreeNode* FindMinNode(BinaryTreeNode* node);

	//! \brief Поиск узла с максимальным значением.
	//! \param node Узел, с которого начинается поиск.
	//! \return Указатель на узел с максимальным значением.
	BinaryTreeNode* FindMaxNode(BinaryTreeNode* node);

	//! \brief Рекурсивное удаление всех узлов дерева.
	//! \param current Узел, который нужно удалить.
	void Clear(BinaryTreeNode* current);

public:
	//! \brief Конструктор по умолчанию. Создает пустое дерево.
	BinaryTree();

	//! \brief Деструктор. Удаляет все узлы дерева.
	~BinaryTree();

	//! \brief Добавление значения в дерево.
	//! \param value Значение для добавления.
	void Add(int value);

	//! \brief Поиск минимального значения в дереве.
	//! \return Минимальное значение в дереве.
	int FindMin();

	//! \brief Поиск максимального значения в дереве.
	//! \return Максимальное значение в дереве.
	int FindMax();

	//! \brief Удаление значения из дерева.
	//! \param value Значение для удаления.
	void Remove(int value);

	//! \brief Поиск узла с заданным значением.
	//! \param data Значение для поиска.
	//! \return Указатель на найденный узел или nullptr, если значение не найдено.
	BinaryTreeNode* Search(int data);

	//! \brief Получение указателя на корневой узел дерева.
	//! \return Указатель на корневой узел.
	BinaryTreeNode* GetRoot();
};
