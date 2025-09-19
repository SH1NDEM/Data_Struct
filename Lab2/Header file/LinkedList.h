#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

//! \brief ����� ������.
class LinkedList
{
public:

    //! \brief ��������� ������� ������.
    struct ListNode
    {
        //! \brief �������� � �������.
        int Value;         

        //! \brief ��������� �� ��������� �������.
        ListNode* NextNode;      

        //! \brief ��������� �� ���������� �������.
        ListNode* PreviosNode;    

        //! \brief
        //! \param nodeValue �������� ����.
        //! \param valueNextNode ��������� �� ��������� ����.
        //! \param valuePreviosNode ��������� �� ���������� ����.
        ListNode(int nodeValue, ListNode* valueNextNode, ListNode* valuePreviosNode);

        //! \brief ����������� �� ���������
        ListNode();
    };

private:

    //! \brief ��������� �� ������ ������
    ListNode* _head = nullptr; 

    //! \brief ��������� �� ����� ������.
    ListNode* _tail = nullptr;

    //! \brief ������� ���������� ��������� � ������.
    int _size = 0;
public:

    //! \brief ����������� �� ���������.
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

    //! \brief ����������
    ~LinkedList();

    //! \brief ��������� ������� � ������ ������.
    //! \param value �������� ������������ ��������.
    void AddElementAtHead(int value);

    //! \brief ��������� ������� � ����� ������.
    //! \param value �������� ������������ ��������.
    void AddElementAtTail(int value);

    //! \brief ��������� ������� ����� ���������� ����.
    //! \param node ��������� �� ����, ����� �������� ����� �������� ����� �������.
    //! \param value �������� ������������ ��������.
    void InsertAfter(ListNode* node, int value);

    //! \brief ���������� ������ �� ������ ������.
    ListNode* GetHead();

    //! \brief ��������� ������� ����� ��������� �����.
    //! \param  node ��������� �� ����, ����� ������� ����� �������� ����� �������.
    //! \param  value �������� ������������ ��������.
    void InsertBefore(ListNode* node, int value);

    //! \brief ��������� ������� �� �������.
    //! \param  index ������, �� �������� ����� �������� ����� �������.
    //! \param value �������� ������������ ��������.
    //! \return ��������� �� ����������� ����.
    ListNode* InsertByIndex(int index, int value);

    //! \brief ������� ������� �� �������.
    //! \param index ������ ���������� ��������.
    void RemoveByIndex(int index);

    //! \brief ��������� ������ ������� ��������
    void BubbleSort();

    //! \brief ��������� �������� ����� ��������.
    //! \param target ��������, ������� ����� �����.
    //! \return ��������� �� ���� � ��������� ��������� ��� nullptr, ���� ������� �� ������.
    int LinearSearch(int target);

    //! \brief ���������� ������� �� �������.
    //! \param ������, �������� �������� ����� �������.
    //! \return ������� �������.
    ListNode* operator[](int index);

    //! \brief ���������� ���������� ��������� � ������.
    int GetSize() const { return _size; }

    //! \brief ���������� ������ ���������� �������� ��� -1, ���� ������ ����.
    int GetLastIndex() const { return _size > 0 ? _size - 1 : -1; }
};
#endif // LINKEDLIST_H
