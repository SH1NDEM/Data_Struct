#pragma once

#include "ringbuffer.h"
//! \brief Очередь на кольцевом буфере.
class QueueRing
{
private:
    //! \brief Указатель на кольцевой буфер.
    RingBuffer* _ringBuffer; 

    //! \brief Размер кольцевого буфера.
    int _sizeBuffer;     

    //! \brief Стандартный размер.
    const int DefoltSize = 4;

    //! \brief Фактор роста.
    const float GrownFactor = 2.0f;

    //! \brief Изменяет размер буфера, увеличивая его на growthFactor.
    //! \param growthFactor Коэффициент увеличения размера буфера.
    void ResizeBuffer(const float& growthFactor);
public:
    //! \brief Конструктор класса QueueRing.
    QueueRing();

    //! \brief Деструктор класса QueueRing.
    ~QueueRing();

    //! \brief Добавляет элемент в очередь.
    //! \param value Значение, которое нужно добавить.
    void Enqueue(const int& value);

    //! \brief Извлекает и возвращает элемент из очереди.
    //! \return Значение извлеченного элемента.  Обработайте случай пустой очереди.
    int Dequeue();
};