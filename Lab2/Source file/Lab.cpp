#include <iostream>
#include <stdexcept>
#include "LinkedList.h" 

bool ValidateInput(int& value)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������� �����." << std::endl;
        return false;
    }

    return true;
}

int main()
{
    setlocale(LC_CTYPE, "rus");

    LinkedList list;
    int choice;
    int value;
    int index;
    int foundIndex;
    LinkedList::ListNode* node = nullptr;

    std::cout << "����:\n";
    std::cout << "1. �������� ������� � ������ ������\n";
    std::cout << "2. �������� ������� � ����� ������\n";
    std::cout << "3. ������� ������� �� �������\n";
    std::cout << "4. ������ ������\n";
    std::cout << "5. �������� ������� �� �������\n";
    std::cout << "6. ����� ��������\n";
    std::cout << "7. ���������� ������\n";
    std::cout << "8. ��������� ��������� �� �������\n";
    std::cout << "9. �������� �� ��������� �������\n";
    std::cout << "10. �������� ����� ��������� �������\n";
    std::cout << "11. ������� ������\n";
    std::cout << "0. �����\n";

    while (true)
    {
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (!ValidateInput(choice)) 
        {
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                std::cout << "������� �������� ��� ���������� � ������: ";
                std::cin >> value;
                list.AddElementAtHead(value);
                break;
            }
            case 2:
            {
                std::cout << "������� �������� ��� ���������� � �����: ";
                std::cin >> value;
                list.AddElementAtTail(value);
                break;
            }
            case 3:
            {
                std::cout << "������� ������ ��� ��������: ";
                std::cin >> index;

                try
                {
                    list.RemoveByIndex(index);
                }
                catch (std::exception) 
                {
                    std::cout << "������� ���������� ������.";
                }

                break;
            }
            case 4:
            {
                std::cout << "���������� ������: ";
                node = list.GetHead();
                while (node != nullptr) 
                {
                    std::cout << node->Value; std::cout << ' ';
                    node = node->NextNode;
                }

                std::cout << "\n";
                break;
            }
            case 5:
            {
                std::cout << "������� ������ ��� �������: ";
                std::cin >> index;
                if (index < 0 || index > list.GetSize())
                {
                    std::cout << "������������ ��������\n";
                    break;
                }
                std::cout << "������� �������� ��� �������: ";
                std::cin >> value;
                list.InsertByIndex(index, value);
                break;
            }
            case 6:
            {
                std::cout << "������� �������� ��� ������: ";
                std::cin >> value;

                foundIndex = list.LinearSearch(value);
                if (foundIndex != -1)
                {
                    std::cout << "������� " << value << " ������. ������: " << 
                        foundIndex << std::endl;
                }
                else
                {
                    std::cout << "������� " << value << " �� ������.\n";
                }

                break;
            }
            case 7:
            {
                list.BubbleSort();
                std::cout << "������ ������������.\n";
                break;
            }
            case 8:
            {
                std::cout << "������� ������ ������������ �������. \n";
                std::cin >> index;

                try
                {
                    node = list[index];
                }
                catch (std::exception)
                {
                    std::cout << "����� �������� ������. \n";
                    break;
                }

                std::cout << "��������� ���������� �������! \n";
                break;
            }
            case 9:
            {
                std::cout << "������� �������� ��� �������\n";
                std::cin >> value;

                if (node != nullptr)
                {
                    list.InsertBefore(node, value);
                    std::cout << "�������! \n";
                }
                break;
            }
            case 10:
            {
                std::cin >> value;

                if (node != nullptr)
                {
                    list.InsertAfter(node, value);
                    std::cout << "�������! \n";
                }

                break;
            }
            case 11:
            {
                std::cout << "������ ������: " << list.GetSize() << std::endl;
                break;
            }

            case 0:
            {
                std::cout << "����� �� ���������.\n";
                return 0;
            }
            default:
            {
                std::cout << "�������� �����. ����������, ���������� �����.\n";
                break;
            }
        }
    }

    return 0;
}


