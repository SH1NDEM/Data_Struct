#pragma once
#include "Stack.h"

//! \brief ������� �� ���� ������.
class QueueStack
{
private:
    //! \brief ��������������� ���� ��� ���������� ���������.
    Stack* _stackIn;  

    //! \brief ��������������� ���� ��� ���������� ���������.
    Stack* _stackOut; 

    //! \brief ����������� ������;
    const int DefoltSize = 4;
public:
    //! \brief ����������� ������ QueueStack.
    QueueStack();

    //! \brief ���������� ������ QueueStack.
    ~QueueStack();

    //! \brief ��������� ������� � �������.
    //! \param value ��������, ������� ����� ��������.
    void Enqueue(const int& value);

    //! \brief ��������� � ���������� ������� �� �������.
    //! \return �������� ������������ ��������. ���������� �������������� ��������, ���� ������� �����.  ����������� ���������� ��������� ������.
    int Dequeue();

    //! \brief �������� ������ ���������� ������.  (��������������, ��� ��� �������� ������, ���������� ��� �����)
    //! \param newSize ����� ������ ������.  ����������� ���������� ��������� ������ (��������, ���� newSize <=0).
    void Resize(int newSize);

};