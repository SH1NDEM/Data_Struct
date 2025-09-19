#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

//! \brief Класс списка.
class LinkedList
{
public:

    //! \brief Структура вершины списка.
    struct ListNode
    {
        //! \brief Значение в вершине.
        int Value;         

        //! \brief Указатель на следующую вершину.
        ListNode* NextNode;      

        //! \brief Указатель на предыдущую вершину.
        ListNode* PreviosNode;    

        //! \brief
        //! \param nodeValue Значение узла.
        //! \param valueNextNode Указатель на следующий узел.
        //! \param valuePreviosNode Указатель на предыдущий узел.
        ListNode(int nodeValue, ListNode* valueNextNode, ListNode* valuePreviosNode);

        //! \brief Конструктор по умолчанию
        ListNode();
    };

private:

    //! \brief Указатель на голову списка
    ListNode* _head = nullptr; 

    //! \brief Указатель на хвост списка.
    ListNode* _tail = nullptr;

    //! \brief Текущее количество элементов в списке.
    int _size = 0;
public:

    //! \brief Конструктор по умолчанию.
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

    //! \brief Деструктор
    ~LinkedList();

    //! \brief Добавляет элемент в начало списка.
    //! \param value Значение добавляемого элемента.
    void AddElementAtHead(int value);

    //! \brief Добавляет элемент в конец списка.
    //! \param value Значение добавляемого элемента.
    void AddElementAtTail(int value);

    //! \brief Вставляет элемент после указанного узла.
    //! \param node Указатель на узел, после которого будет вставлен новый элемент.
    //! \param value Значение добавляемого элемента.
    void InsertAfter(ListNode* node, int value);

    //! \brief Возвращает ссылку на голову списка.
    ListNode* GetHead();

    //! \brief Вставляет элемент перед указанным узлом.
    //! \param  node Указатель на узел, перед которым будет вставлен новый элемент.
    //! \param  value Значение добавляемого элемента.
    void InsertBefore(ListNode* node, int value);

    //! \brief Вставляет элемент по индексу.
    //! \param  index Индекс, по которому будет вставлен новый элемент.
    //! \param value Значение добавляемого элемента.
    //! \return Указатель на вставленный узел.
    ListNode* InsertByIndex(int index, int value);

    //! \brief Удаляет элемент по индексу.
    //! \param index Индекс удаляемого элемента.
    void RemoveByIndex(int index);

    //! \brief Сортирует список методом пузырька
    void BubbleSort();

    //! \brief Выполняет линейный поиск элемента.
    //! \param target Значение, которое нужно найти.
    //! \return Указатель на узел с найденным значением или nullptr, если элемент не найден.
    int LinearSearch(int target);

    //! \brief Возвращает элемент по индексу.
    //! \param Индекс, значение которого нужно вернуть.
    //! \return Искомая вершина.
    ListNode* operator[](int index);

    //! \brief Возвращает количество элементов в списке.
    int GetSize() const { return _size; }

    //! \brief Возвращает индекс последнего элемента или -1, если список пуст.
    int GetLastIndex() const { return _size > 0 ? _size - 1 : -1; }
};
#endif // LINKEDLIST_H
