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
        cout << "������� ������������ �������:" << endl;
        cout << "0 - ���������� ������ ���������" << endl;
        cout << "1 - �������� ������� � ������" << endl;
        cout << "2 - �������� ������� � �����" << endl;
        cout << "3 - �������� ������� �� �������" << endl;
        cout << "4 - ������� �� �������" << endl;
        cout << "5 - ������� �� ��������" << endl;
        cout << "6 - ������� ������� �� �������" << endl;
        cout << "7 - ������� ������" << endl;
        cout << "8 - ������������� ������" << endl;
        cout << "9 - �������� ����� �������� � �������" << endl;
        cout << "10 - �������� ����� �������� � �������" << endl;
        cout << "11 - ������� �����������" << endl;
        cout << "12 - ������� ���������� ���������" << endl;

        cin >> answer;

        switch (answer)
        {
        case 0:
            flag = false;
            break;
        case 1: {
            int value;
            cout << "������� �������� ��� ���������� � ������: ";
            cin >> value;
            dynamicArray.AddElementAtStart(value);
            break;
        }
        case 2: {
            int value;
            cout << "������� �������� ��� ���������� � �����: ";
            cin >> value;
            dynamicArray.AddElementAtEnd(value);
            break;
        }
        case 3: {
            int index, value;
            cout << "������� ������ � �������� ��� ����������: ";
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
            cout << "������� ������ ��� ��������: ";
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
            cout << "������� �������� ��� ��������: ";
            cin >> value;
            dynamicArray.RemoveByValue(value);
            break;
        }
        case 6: {
            int index;
            cout << "������� ������ ��� ������: ";
            cin >> index;
            try {
                cout << "�������: " << dynamicArray.GetElement(index) << endl;
            }
            catch (const std::out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 7: {
            cout << "������: ";
            for (int i = 0; i < dynamicArray.GetSize(); i++)
            {
                cout << dynamicArray.GetArray()[i] << " ";
            }
            cout << endl;
            break;
        }
        case 8:
            dynamicArray.SortArray();
            cout << "������ ������������." << endl;
            break;
        case 9: {
            int value;
            cout << "������� �������� ��� ��������� ������: ";
            cin >> value;
            int index = dynamicArray.LinearSearch(value);
            if (index != -1) {
                cout << "������� ������ �� �������: " << index << endl;
            }
            else {
                cout << "������� �� ������." << endl;
            }
            break;
        }
        case 10: {
            int value;
            cout << "������� �������� ��� ��������� ������: ";
            cin >> value;
            int result = dynamicArray.BinarySearch(value);
            if (result == -1) 
            {
                cout << "������� �� ������.";
                break;
            }
            cout << "������ ��������: " << result << endl;
            break;
        }
        case 11:
            cout << "����������� �������: " << dynamicArray.GetCapacity() << endl;
            break;
        case 12:
            cout << "���������� ��������� � �������: " << dynamicArray.GetSize() << endl;
            break;
        default:
            cout << "�������� �������. ���������� �����." << endl;
            break;
        }
    }

    return 0;
}

