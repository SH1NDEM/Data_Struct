#include <iostream>
#include "LinkedList.h"
using namespace std;


LinkedList::ListNode::ListNode(int nodeValue, ListNode* valueNextNode, ListNode* valuePreviosNode)
    : Value(nodeValue), NextNode(valueNextNode), PreviosNode(valuePreviosNode) {}
LinkedList::ListNode::ListNode() : Value(0), NextNode(nullptr), PreviosNode(nullptr) {}

LinkedList::~LinkedList() 
{
    while (_head != nullptr) 
    {
        ListNode* temp = _head;
        _head = _head->NextNode;
        delete temp;
    }
}

void LinkedList::AddElementAtHead(int value) 
{
    ListNode* node = new ListNode(value, _head, nullptr);

    if (_head != nullptr) 
    {
        _head->PreviosNode = node;
    }
    else 
    {
        _tail = node;
    }

    _head = node;
    ++_size;
}

void LinkedList::AddElementAtTail(int value) 
{
    ListNode* node = new ListNode(value, nullptr, _tail);

    if (_tail != nullptr) 
    {
        _tail->NextNode = node;
    }
    else 
    {
        _head = node;
    }

    _tail = node;
    ++_size;
}

void LinkedList::InsertAfter(ListNode* node, int value) 
{
    ListNode* newNode = new ListNode(value, node->NextNode, node);

    if (node->NextNode != nullptr) 
    {
        node->NextNode->PreviosNode = newNode;
    }
    else 
    {
        _tail = newNode;
    }

    node->NextNode = newNode;
    ++_size;
}

void LinkedList::InsertBefore(ListNode* node, int value) 
{
    ListNode* newNode = new ListNode(value, node, node->PreviosNode);

    if (node->PreviosNode != nullptr) {
        node->PreviosNode->NextNode = newNode;
    }
    else 
    {
        _head = newNode;
    }

    node->PreviosNode = newNode;
    ++_size;
}

LinkedList::ListNode* LinkedList::InsertByIndex(int index, int value)
{
    if (index == 0)
    {
        AddElementAtHead(value);
        return _head;
    }

    // вставка в конец
    if (index == _size)
    {
        AddElementAtTail(value);
        return _tail;
    }

    // вставка в середину
    ListNode* selectedNode = _head;
    for (int i = 0; i < index; i++)
    {
        selectedNode = selectedNode->NextNode;
    }

    ListNode* newNode = new ListNode(value, selectedNode, selectedNode->PreviosNode);
    selectedNode->PreviosNode->NextNode = newNode;
    selectedNode->PreviosNode = newNode;

    ++_size;
    return newNode;
}

void LinkedList::RemoveByIndex(int index) 
{
    
    if (index < 0) 
    {
        throw std::exception("Index out of bounds.");
        return;
    }

    ListNode* selectedNode = _head;

    for (int i = 0; i < index; i++) 
    {
        if (selectedNode == nullptr) {
            throw std::exception("Index out of bounds.");
            return;
        }

        selectedNode = selectedNode->NextNode;
    }

    if (selectedNode == nullptr) 
    {
        throw std::exception("Index out of bounds.");
        return;
    }

    if (selectedNode->PreviosNode != nullptr) 
    {
        selectedNode->PreviosNode->NextNode = selectedNode->NextNode;
    }
    else 
    {
        _head = selectedNode->NextNode;
    }

    if (selectedNode->NextNode != nullptr) 
    {
        selectedNode->NextNode->PreviosNode = selectedNode->PreviosNode;
    }
    else
    {
        _tail = selectedNode->PreviosNode;
    }
    delete selectedNode;
    --_size;
}

void LinkedList::BubbleSort() {

    if (_head == nullptr) return;

    bool swapped;

    do 
    {
        swapped = false;
        ListNode* current = _head;
        while (current != nullptr && current->NextNode != nullptr) 
        {
            if (current->Value > current->NextNode->Value) {
                int temp = current->Value;
                current->Value = current->NextNode->Value;
                current->NextNode->Value = temp;
                swapped = true;
            }

            current = current->NextNode;
        }

    } 
    while (swapped);
}

int LinkedList::LinearSearch(int target)
{
    ListNode* current = _head;
    int nodeIndex = 0;

    while (current != nullptr)
    {
        if (current->Value == target)
        {
            return nodeIndex;
        }

        nodeIndex++;
        current = current->NextNode;
    }

    return -1;
}

LinkedList::ListNode* LinkedList::operator[](int index) 
{
    if (index < 0) 
    {
        throw std::exception("Index out of bounds.");
    }

    ListNode* current = _head;
    int currentIndex = 0;

    while (current != nullptr) {
        if (currentIndex == index) 
        {
            return current; 
        }

        current = current->NextNode;
        currentIndex++;
    }

    throw std::exception("Index out of bounds."); 
}

LinkedList::ListNode* LinkedList::GetHead()
{
    return _head;
}