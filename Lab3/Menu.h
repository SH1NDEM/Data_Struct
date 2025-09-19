#define MENU_H

#include "Stack.h"       
#include "RingBuffer.h"   
#include "QueueStack.h"        
#include "QueueRing.h" 

//! \brief ���������� ������� ����.
void ShowMenu();

//! \brief ���������� ���� ��� ������ �� ������.
//! \param stack ��������� �� ������ ������ Stack.
void ShowStackMenu(Stack* stack);

//! \brief ���������� ���� ��� ������ � ��������� �������.
//! \param rb ��������� �� ������ ������ RingBuffer.
void ShowRingBufferMenu(RingBuffer* rb);

//! \brief ���������� ���� ��� ������ � �������� (������������� � ������� ���� ������).
//! \param queue ��������� �� ������ ������ QueueStack.
void ShowQueueMenu(QueueStack* queue);

//! \brief ���������� ���� ��� ������ � �������� (������������� � ������� ���������� ������).
//! \param queue ��������� �� ������ ������ QueueRing.
void ShowQueue2StacksMenu(QueueRing* queue);

//! \brief ������� ����� �����.
void ClearInput();

//! \brief �������� ����� ����� �� ������������.
//! \return ��������� ������������� ����� �����.  ����������� ��������� ������ ����� (��������, ���� ���������� ��������).
int GetIntegerInput();
