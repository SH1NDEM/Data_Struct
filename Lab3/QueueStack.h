#pragma once
#include "Stack.h"

//! \brief Очередь на двух стаках.
class QueueStack
{
private:
    //! \brief Вспомогательный стек для добавления элементов.
    Stack* _stackIn;  

    //! \brief Вспомогательный стек для извлечения элементов.
    Stack* _stackOut; 

    //! \brief Стандартный размер;
    const int DefoltSize = 4;
public:
    //! \brief Конструктор класса QueueStack.
    QueueStack();

    //! \brief Деструктор класса QueueStack.
    ~QueueStack();

    //! \brief Добавляет элемент в очередь.
    //! \param value Значение, которое нужно добавить.
    void Enqueue(const int& value);

    //! \brief Извлекает и возвращает элемент из очереди.
    //! \return Значение извлеченного элемента. Возвращает неопределенное значение, если очередь пуста.  Рассмотрите добавление обработки ошибки.
    int Dequeue();

    //! \brief Изменяет размер внутренних стеков.  (Предполагается, что это изменяет размер, выделенный под стеки)
    //! \param newSize Новый размер стеков.  Рассмотрите добавление обработки ошибок (например, если newSize <=0).
    void Resize(int newSize);

};