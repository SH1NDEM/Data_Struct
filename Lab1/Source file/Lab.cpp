#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");

    DynamicArray dynamicArray;
    int answer;
    bool flag = true;

    while (flag)
    {
        cout << "Введите интересующий вариант:" << endl;
        cout << "0 - завершение работы программы" << endl;
        cout << "1 - добавить элемент в начало" << endl;
        cout << "2 - добавить элемент в конец" << endl;
        cout << "3 - добавить элемент по индексу" << endl;
        cout << "4 - удалить по индексу" << endl;
        cout << "5 - удалить по значению" << endl;
        cout << "6 - вывести элемент по индексу" << endl;
        cout << "7 - вывести массив" << endl;
        cout << "8 - отсортировать массив" << endl;
        cout << "9 - линейный поиск элемента в массиве" << endl;
        cout << "10 - бинарный поиск элемента в массиве" << endl;
        cout << "11 - вывести вместимость" << endl;
        cout << "12 - вывести количество элементов" << endl;

        cin >> answer;

        switch (answer)
        {
        case 0:
            flag = false;
            break;
        case 1: {
            int value;
            cout << "Введите значение для добавления в начало: ";
            cin >> value;
            dynamicArray.AddElementAtStart(value);
            break;
        }
        case 2: {
            int value;
            cout << "Введите значение для добавления в конец: ";
            cin >> value;
            dynamicArray.AddElementAtEnd(value);
            break;
        }
        case 3: {
            int index, value;
            cout << "Введите индекс и значение для добавления: ";
            cin >> index >> value;
            try {
                dynamicArray.AddElementByIndex(index, value);
            }
            catch (const std::out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            int index;
            cout << "Введите индекс для удаления: ";
            cin >> index;
            try {
                dynamicArray.RemoveByIndex(index);
            }
            catch (const std::out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 5: {
            int value;
            cout << "Введите значение для удаления: ";
            cin >> value;
            dynamicArray.RemoveByValue(value);
            break;
        }
        case 6: {
            int index;
            cout << "Введите индекс для вывода: ";
            cin >> index;
            try {
                cout << "Элемент: " << dynamicArray.GetElement(index) << endl;
            }
            catch (const std::out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 7: {
            cout << "Массив: ";
            for (int i = 0; i < dynamicArray.GetSize(); i++)
            {
                cout << dynamicArray.GetArray()[i] << " ";
            }
            cout << endl;
            break;
        }
        case 8:
            dynamicArray.SortArray();
            cout << "Массив отсортирован." << endl;
            break;
        case 9: {
            int value;
            cout << "Введите значение для линейного поиска: ";
            cin >> value;
            int index = dynamicArray.LinearSearch(value);
            if (index != -1) {
                cout << "Элемент найден на индексе: " << index << endl;
            }
            else {
                cout << "Элемент не найден." << endl;
            }
            break;
        }
        case 10: {
            int value;
            cout << "Введите значение для бинарного поиска: ";
            cin >> value;
            int result = dynamicArray.BinarySearch(value);
            if (result == -1) 
            {
                cout << "Элемент не найден.";
                break;
            }
            cout << "Индекс элемента: " << result << endl;
            break;
        }
        case 11:
            cout << "Вместимость массива: " << dynamicArray.GetCapacity() << endl;
            break;
        case 12:
            cout << "Количество элементов в массиве: " << dynamicArray.GetSize() << endl;
            break;
        default:
            cout << "Неверный вариант. Попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}

