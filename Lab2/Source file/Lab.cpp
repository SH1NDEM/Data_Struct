#include <iostream>
#include <stdexcept>
#include "LinkedList.h" 

bool ValidateInput(int& value)
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите число." << std::endl;
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

    std::cout << "Меню:\n";
    std::cout << "1. Добавить элемент в начало списка\n";
    std::cout << "2. Добавить элемент в конец списка\n";
    std::cout << "3. Удалить элемент по индексу\n";
    std::cout << "4. Печать списка\n";
    std::cout << "5. Вставить элемент по индексу\n";
    std::cout << "6. Поиск элемента\n";
    std::cout << "7. Сортировка списка\n";
    std::cout << "8. Поставить указатель на вершину\n";
    std::cout << "9. Вставить до указанной вершины\n";
    std::cout << "10. Вставить после указанной вершины\n";
    std::cout << "11. вывести размер\n";
    std::cout << "0. Выход\n";

    while (true)
    {
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        if (!ValidateInput(choice)) 
        {
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите значение для добавления в начало: ";
                std::cin >> value;
                list.AddElementAtHead(value);
                break;
            }
            case 2:
            {
                std::cout << "Введите значение для добавления в конец: ";
                std::cin >> value;
                list.AddElementAtTail(value);
                break;
            }
            case 3:
            {
                std::cout << "Введите индекс для удаления: ";
                std::cin >> index;

                try
                {
                    list.RemoveByIndex(index);
                }
                catch (std::exception) 
                {
                    std::cout << "Введите корректный индекс.";
                }

                break;
            }
            case 4:
            {
                std::cout << "Содержимое списка: ";
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
                std::cout << "Введите индекс для вставки: ";
                std::cin >> index;
                if (index < 0 || index > list.GetSize())
                {
                    std::cout << "Недопустимое значение\n";
                    break;
                }
                std::cout << "Введите значение для вставки: ";
                std::cin >> value;
                list.InsertByIndex(index, value);
                break;
            }
            case 6:
            {
                std::cout << "Введите значение для поиска: ";
                std::cin >> value;

                foundIndex = list.LinearSearch(value);
                if (foundIndex != -1)
                {
                    std::cout << "Элемент " << value << " найден. Индекс: " << 
                        foundIndex << std::endl;
                }
                else
                {
                    std::cout << "Элемент " << value << " не найден.\n";
                }

                break;
            }
            case 7:
            {
                list.BubbleSort();
                std::cout << "Список отсортирован.\n";
                break;
            }
            case 8:
            {
                std::cout << "Введите индекс интересующей вершины. \n";
                std::cin >> index;

                try
                {
                    node = list[index];
                }
                catch (std::exception)
                {
                    std::cout << "Введён неверный индекс. \n";
                    break;
                }

                std::cout << "Указатель установлен успешно! \n";
                break;
            }
            case 9:
            {
                std::cout << "Укажите значение для вставки\n";
                std::cin >> value;

                if (node != nullptr)
                {
                    list.InsertBefore(node, value);
                    std::cout << "Успешно! \n";
                }
                break;
            }
            case 10:
            {
                std::cin >> value;

                if (node != nullptr)
                {
                    list.InsertAfter(node, value);
                    std::cout << "Успешно! \n";
                }

                break;
            }
            case 11:
            {
                std::cout << "Размер списка: " << list.GetSize() << std::endl;
                break;
            }

            case 0:
            {
                std::cout << "Выход из программы.\n";
                return 0;
            }
            default:
            {
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                break;
            }
        }
    }

    return 0;
}


