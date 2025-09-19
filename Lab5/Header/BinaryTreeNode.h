#pragma once

//! \brief —труктура дл€ представлени€ узла бинарного дерева.
struct BinaryTreeNode
{
public:
    //! \brief «начение, хран€щеес€ в узле.
    int Value;

    //! \brief ”казатель на левый дочерний узел.
    BinaryTreeNode* Left;

    //! \brief ”казатель на правый дочерний узел.
    BinaryTreeNode* Right;

    //! \brief  онструктор дл€ создани€ узла с заданным значением.
    //! \param value «начение, которое будет хранитьс€ в узле.
    BinaryTreeNode(int value);
};
