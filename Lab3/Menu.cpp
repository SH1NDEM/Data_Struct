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
                std::cout << "������� ��������������� �����. " << endl;
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
        std::cout << "������ �� ������. ���� ��������: " << endl;
        std::cout << "1 - ��������� ������� � ����.  " << endl;
        std::cout << "2 - ������� ������� �� �����. " << endl;
        std::cout << "3 - �������� ������ �����. " << endl;
        std::cout << "0 - �����. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "������� ������� ��� �������:" << endl;

                value = GetIntegerInput();

                try
                { 
                    stack->Push(value);
                }
                catch (std::exception)
                {
                    std::cout << "���� ����������!" << endl;
                    break;
                }

                std::cout << "������� ��������!" << endl;
                break;
            }
            case 2:
            {
                if (!stack->IsEmpty())
                {
                    value = stack->Pop();
                    cout << "������� �� �����: " << value << endl;
                }
                else
                {
                    std::cout << "���� ����." << endl;
                }

                break;
            }
            case 3:
            {
                std::cout << "������� ����� ������ �����." << endl;

                newSize = GetIntegerInput();

                stack->Resize(newSize);
                std::cout << "������ ������." << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "������� ���������� �������." << endl;
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
        std::cout << "������ �� �������. ���� ��������: " << endl;
        std::cout << "1 - ��������� ������� � �����.  " << endl;
        std::cout << "2 - ������� ������� �� ������. " << endl;
        std::cout << "3 - �������� ������ ������. " << endl;
        std::cout << "4 - ������� ��������� ������������. " << endl;
        std::cout << "5 - ������� ������� ������������. " << endl;
        std::cout << "0 - �����. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "������� ������� ��� �����:" << endl;

                value = GetIntegerInput();

                rb->Push(value);
                break;
            }
            case 2:
            {
                try 
                {
                    value = rb->Pop();
                    std::cout << "��������: " << value << endl;
                }
                catch (std::exception) 
                {
                    std::cout << "����� ����." << endl;
                }

                break;
            }
            case 3:
            {
                std::cout << "������� ����� ������: " << endl;

                newSize = GetIntegerInput();

                rb->Resize(newSize);

                std::cout << "������ ������!" << endl;
            }
            case 4:
            {
                std::cout << "��������� �����: " << rb->GetFreeSpace() << endl;
                break;
            }
            case 5:
            {
                std::cout << "������� �����: " << rb->GetUsedSize() << endl;
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
        std::cout << "������ � ��������. ���� ��������: " << endl;
        std::cout << "1 - ��������� ������� � �������.  " << endl;
        std::cout << "2 - ������� ������� �� �������. " << endl;
        std::cout << "0 - �����. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "������� ������� ��� �������: " << endl;

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
                    std::cout << "������� �����." << endl;
                    break;
                }

                std::cout << "������� �� �������: " << value << endl;
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "������� ���������� ��������! " << endl;
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
        std::cout << "������ � ��������. ���� ��������: " << endl;
        std::cout << "1 - ��������� ������� � �������.  " << endl;
        std::cout << "2 - ������� ������� �� �������. " << endl;
        std::cout << "3 - �������� ������ ������ � �������. " << endl;
        std::cout << "0 - �����. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "������� ������� ��� �������: " << endl;

                value = GetIntegerInput();

                try
                {
                    queue->Enqueue(value);
                }
                catch (std::exception)
                {
                    std::cout << "������� �����������!" << endl;
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
                    std::cout << "������� �����." << endl;
                    break;
                }

                std::cout << "������� �� �������: " << value << endl;
                break;
            }
            case 3:
            {
                std::cout << "������� ����� ������ ������:  " << endl;

                newSize = GetIntegerInput();

                queue->Resize(newSize);
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "������� ���������� ��������! " << endl;
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
        cout << "\n�������� �� ��� ������\n";
        cout << "1. ����.\n";
        cout << "2. ��������� �����.\n";
        cout << "3. ������� �� ������.\n";
        cout << "4. ������� �� 2 ������.\n";
        cout << "0. �����.\n";

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
                cout << "������� ���������� ������.\n";
            }
        }
    } while (choice != 0);

    delete stack;
    delete ringBuffer;
    delete queue;
    delete queue2Stacks;
}