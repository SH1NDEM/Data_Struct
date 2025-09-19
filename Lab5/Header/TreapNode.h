#pragma once
#include <iostream>

//! \brief Структура для представления узла дерева Treap.
struct TreapNode
{
public:
    //! \brief Ключ узла, определяющий его позицию в дереве.
    int Key;

    //! \brief Приоритет узла, используемый для соблюдения свойств кучи.
    int Priority;

    //! \brief Указатель на левый дочерний узел.
    TreapNode* Left;

    //! \brief Указатель на правый дочерний узел.
    TreapNode* Right;

    //! \brief Конструктор для создания узла с заданным ключом.
    //! \param k Ключ для нового узла.
    TreapNode(int k);
};
