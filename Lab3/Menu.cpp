#include <iostream>
#include "Menu.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueRing.h"
#include "QueueStack.h"

using namespace std;

void ClearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int GetIntegerInput()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            if (value < 0)
            {
                ClearInput();
                std::cout << "Введите неотрицательное число. " << endl;
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else
        {
            ClearInput();
        }
    }
}

void ShowStackMenu(Stack* stack)
{
    int choice;
    int value; 
    int newSize;

    do
    {
        std::cout << "Работа со стеком. Ваше действие: " << endl;
        std::cout << "1 - Поместить элемент в стек.  " << endl;
        std::cout << "2 - Достать элемент из стека. " << endl;
        std::cout << "3 - Изменить размер стека. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для вставки:" << endl;

                value = GetIntegerInput();

                try
                { 
                    stack->Push(value);
                }
                catch (std::exception)
                {
                    std::cout << "Стек переполнен!" << endl;
                    break;
                }

                std::cout << "Элемент добавлен!" << endl;
                break;
            }
            case 2:
            {
                if (!stack->IsEmpty())
                {
                    value = stack->Pop();
                    cout << "Элемент из стека: " << value << endl;
                }
                else
                {
                    std::cout << "Стек пуст." << endl;
                }

                break;
            }
            case 3:
            {
                std::cout << "Введите новый размер стека." << endl;

                newSize = GetIntegerInput();

                stack->Resize(newSize);
                std::cout << "Размер изменён." << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "Введите корректный элемент." << endl;
                break;
            }
        }
    } while (choice != 0);
}

void ShowRingBufferMenu(RingBuffer* rb)
{
    int choice;
    int value;
    int newSize;

    do
    {
        std::cout << "Работа со буфером. Ваше действие: " << endl;
        std::cout << "1 - Поместить элемент в буфер.  " << endl;
        std::cout << "2 - Достать элемент из буфера. " << endl;
        std::cout << "3 - Изменить размер буфера. " << endl;
        std::cout << "4 - Вывести свободное пространство. " << endl;
        std::cout << "5 - Вывести занятое пространство. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для ввода:" << endl;

                value = GetIntegerInput();

                rb->Push(value);
                break;
            }
            case 2:
            {
                try 
                {
                    value = rb->Pop();
                    std::cout << "Эелемент: " << value << endl;
                }
                catch (std::exception) 
                {
                    std::cout << "Буфер пуст." << endl;
                }

                break;
            }
            case 3:
            {
                std::cout << "Введите новый размер: " << endl;

                newSize = GetIntegerInput();

                rb->Resize(newSize);

                std::cout << "Размер изменён!" << endl;
            }
            case 4:
            {
                std::cout << "Свободное место: " << rb->GetFreeSpace() << endl;
                break;
            }
            case 5:
            {
                std::cout << "Занятое место: " << rb->GetUsedSize() << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                break;
            }
        }
    } while (choice != 0);
}

void ShowQueueMenu(QueueRing* queue)
{
    int choice;
    int value;

    do
    {
        std::cout << "Работа с очередью. Ваше действие: " << endl;
        std::cout << "1 - Поместить элемент в очередь.  " << endl;
        std::cout << "2 - Достать элемент из очереди. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для вставки: " << endl;

                value = GetIntegerInput();

                queue->Enqueue(value);
                break;
            }
            case 2:
            {
                try 
                {
                    value = queue->Dequeue();
                }
                catch (std::exception) 
                {
                    std::cout << "Очередь пуста." << endl;
                    break;
                }

                std::cout << "Элемент из очереди: " << value << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "Введите корректное значение! " << endl;
            }
        }
    } while (choice != 0);
}

void ShowQueue2StacksMenu(QueueStack* queue)
{
    int choice;
    int value;
    int newSize;

    do
    {
        std::cout << "Работа с очередью. Ваше действие: " << endl;
        std::cout << "1 - Поместить элемент в очередь.  " << endl;
        std::cout << "2 - Достать элемент из очереди. " << endl;
        std::cout << "3 - Изменить размер стеков в очереди. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для вставки: " << endl;

                value = GetIntegerInput();

                try
                {
                    queue->Enqueue(value);
                }
                catch (std::exception)
                {
                    std::cout << "Очередь переполнена!" << endl;
                }
                break;
            }
            case 2:
            {
                try
                {
                    value = queue->Dequeue();
                }
                catch (std::exception)
                {
                    std::cout << "Очередь пуста." << endl;
                    break;
                }

                std::cout << "Элемент из очереди: " << value << endl;
                break;
            }
            case 3:
            {
                std::cout << "Введите новый размер стеков:  " << endl;

                newSize = GetIntegerInput();

                queue->Resize(newSize);
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "Введите корректное значение! " << endl;
            }
        }
    } while (choice != 0);
}

void ShowMenu()
{
    int choice;
    int stackSize = 4;
    int bufferSize = 10;
    Stack* stack = new Stack(stackSize);
    RingBuffer* ringBuffer = new RingBuffer(bufferSize);
    QueueRing* queue = new QueueRing();
    QueueStack* queue2Stacks = new QueueStack();

    do
    {
        cout << "\nВыберите СЛ для работы\n";
        cout << "1. Стек.\n";
        cout << "2. Кольцевой буфер.\n";
        cout << "3. Очередь на буфере.\n";
        cout << "4. Очередь на 2 стеках.\n";
        cout << "0. Выход.\n";

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                ShowStackMenu(stack);
                break;
            }
            case 2:
            {
                ShowRingBufferMenu(ringBuffer);
                break;
            }
            case 3:
            {
                ShowQueueMenu(queue);
                break;
            }
            case 4:
            {
                ShowQueue2StacksMenu(queue2Stacks);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                cout << "Введите корректный символ.\n";
            }
        }
    } while (choice != 0);

    delete stack;
    delete ringBuffer;
    delete queue;
    delete queue2Stacks;
}