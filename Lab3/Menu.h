#define MENU_H

#include "Stack.h"       
#include "RingBuffer.h"   
#include "QueueStack.h"        
#include "QueueRing.h" 

//! \brief Отображает главное меню.
void ShowMenu();

//! \brief Отображает меню для работы со стеком.
//! \param stack Указатель на объект класса Stack.
void ShowStackMenu(Stack* stack);

//! \brief Отображает меню для работы с кольцевым буфером.
//! \param rb Указатель на объект класса RingBuffer.
void ShowRingBufferMenu(RingBuffer* rb);

//! \brief Отображает меню для работы с очередью (реализованной с помощью двух стеков).
//! \param queue Указатель на объект класса QueueStack.
void ShowQueueMenu(QueueStack* queue);

//! \brief Отображает меню для работы с очередью (реализованной с помощью кольцевого буфера).
//! \param queue Указатель на объект класса QueueRing.
void ShowQueue2StacksMenu(QueueRing* queue);

//! \brief Очищает буфер ввода.
void ClearInput();

//! \brief Получает целое число от пользователя.
//! \return Введенное пользователем целое число.  Рассмотрите обработку ошибок ввода (например, ввод нечисловых значений).
int GetIntegerInput();
