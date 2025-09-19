#include "Treap.h"

Treap::Treap() : _root(nullptr) {};

void Treap::Split(TreapNode* current, int key, TreapNode*& left, TreapNode*& right) 
{
    if (!current) 
    {
        left = right = nullptr;
    }
    else if (current->Key <= key) 
    {
       Split(current->Right, key, current->Right, right);
        left = current;
    }
    else 
    {
        Split(current->Left, key, left, current->Left);
        right = current;
    }
}


TreapNode* Treap::Merge(TreapNode* left, TreapNode* right) 
{
    if (!left || !right) return left ? left : right;

    if (left->Priority > right->Priority) 
    {
        left->Right = Merge(left->Right, right);
        return left;
    }
    else 
    {
        right->Left = Merge(left, right->Left);
        return right;
    }
}

void Treap::AddUnoptimized(int key) 
{
    TreapNode* newNode = new TreapNode(key);
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;

    Split(_root, key, left, right);

    _root = Merge(Merge(left, newNode), right);
}

TreapNode* Treap::AddOptimized(TreapNode* current, int key) 
{
    if (!current) return new TreapNode(key);

    if (current->Priority < rand()) 
    {
        TreapNode* newNode = new TreapNode(key);
        Split(current, key, newNode->Left, newNode->Right);

        return newNode;
    }

    if (key < current->Key)
    {
        current->Left = AddOptimized(current->Left, key);
    }
    else
    {
        current->Right = AddOptimized(current->Right, key);
    }

    return current;
}

void Treap::RemoveUnoptimized(int key) 
{
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    TreapNode* mid = nullptr;

    Split(_root, key - 1, left, right);
    Split(right, key, mid, right);

    delete mid;

    _root = Merge(left, right);
}

TreapNode* Treap::RemoveOptimized(TreapNode* current, int key)
{
    if (!current) return nullptr;

    if (current->Key == key) 
    {
        TreapNode* result = Merge(current->Left, current->Right);
        delete current;
        return result;
    }

    if (key < current->Key)
    {
        current->Left = RemoveOptimized(current->Left, key);
    }
    else
    {
        current->Right = RemoveOptimized(current->Right, key);
    }

    return current;
}

void Treap::AddOptimized(int key)
{
    _root = AddOptimized(_root, key);
}

void Treap::RemoveOptimized(int key) 
{
    _root = RemoveOptimized(_root, key);
}

TreapNode* Treap::Search(TreapNode* node, int data)
{
    if (!node)
    {
        return nullptr;
    }

    if (data == node->Key)
    {
        return node;
    }

    if (data < node->Key)
    {
        return Search(node->Left, data);
    }
    else
    {
        return Search(node->Right, data);
    }
}

TreapNode* Treap::Search(int data) 
{
    return Search(_root, data);
}

void Treap::Clear(TreapNode* current) 
{
    if (!current) return;

    Clear(current->Left);
    Clear(current->Right);

    delete current;
}

TreapNode* Treap::GetRoot()
{
    return _root;
}

Treap:: ~Treap() 
{
    Clear(_root);
}