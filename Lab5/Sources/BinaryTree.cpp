#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    _root = nullptr;
}

void BinaryTree::Add(BinaryTreeNode* &node, int data)
{
    if (!node)
    {
        node = new BinaryTreeNode(data);
        return;
    }

    if (data < node->Value)
    {
        Add(node->Left, data);
    }
    else
    {
        Add(node->Right, data);
    }
}

void BinaryTree::Add(int value) 
{
	Add(_root, value);
}

BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* node, int value)
{
    if (!node) return nullptr;

    if (value < node->Value) 
    {
        node->Left = RemoveNode(node->Left, value);
    }
    else if (value > node->Value) 
    {
        node->Right = RemoveNode(node->Right, value);
    }
    else 
    {
        if (!node->Left) 
        {
            BinaryTreeNode* temp = node->Right;
            delete node;
            return temp;
        }
        else if (!node->Right) 
        {
            BinaryTreeNode* temp = node->Left;
            delete node;
            return temp;
        }

        BinaryTreeNode* temp = FindMinNode(node->Right);
        node->Value = temp->Value;
        node->Right = RemoveNode(node->Right, temp->Value);
    }

    return node;
}

int BinaryTree::FindMin()
{
    if (!_root) throw std::runtime_error("Дерево пусто.");
    return FindMinNode(_root)->Value;
}

BinaryTreeNode* BinaryTree::FindMinNode(BinaryTreeNode* node)
{
    while (node->Left) node = node->Left;
    return node;
}

void BinaryTree::Remove(int value) 
{
    _root = RemoveNode(_root, value);
}

BinaryTreeNode* BinaryTree::Search(BinaryTreeNode* node, int data)
{
    if (!node)
    {
        return nullptr;
    }

    if (data == node->Value)
    {
        return node;
    }

    if (data < node->Value)
    {
        return Search(node->Left, data);
    }
    else
    {
        return Search(node->Right, data);
    }
}

BinaryTreeNode* BinaryTree::Search(int data)
{
    return Search(_root, data);
}

BinaryTreeNode* BinaryTree::FindMaxNode(BinaryTreeNode* node) 
{
    while (node->Right) node = node->Right;
    return node;
}

int BinaryTree::FindMax()
{
    if (!_root) throw std::runtime_error("Дерево пусто.");
    return FindMaxNode(_root)->Value;
}

BinaryTreeNode* BinaryTree::GetRoot()
{
    return _root;
}

void BinaryTree::Clear(BinaryTreeNode* current)
{
    if (current == nullptr) return;
 
    Clear(current->Left);
    Clear(current->Right);

    delete current;
}


BinaryTree::~BinaryTree() 
{
    Clear(_root);
}