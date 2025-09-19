#pragma once

#include "ringbuffer.h"
//! \brief ������� �� ��������� ������.
class QueueRing
{
private:
    //! \brief ��������� �� ��������� �����.
    RingBuffer* _ringBuffer; 

    //! \brief ������ ���������� ������.
    int _sizeBuffer;     

    //! \brief ����������� ������.
    const int DefoltSize = 4;

    //! \brief ������ �����.
    const float GrownFactor = 2.0f;

    //! \brief �������� ������ ������, ���������� ��� �� growthFactor.
    //! \param growthFactor ����������� ���������� ������� ������.
    void ResizeBuffer(const float& growthFactor);
public:
    //! \brief ����������� ������ QueueRing.
    QueueRing();

    //! \brief ���������� ������ QueueRing.
    ~QueueRing();

    //! \brief ��������� ������� � �������.
    //! \param value ��������, ������� ����� ��������.
    void Enqueue(const int& value);

    //! \brief ��������� � ���������� ������� �� �������.
    //! \return �������� ������������ ��������.  ����������� ������ ������ �������.
    int Dequeue();
};