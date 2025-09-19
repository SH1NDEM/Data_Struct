#include "Menu.h"

void MenuController()
{
    string menu = "�������� ���� �� ��������:\n1 - ��������\n2 - �����\
        \n3 - �������\n4 - �������� ���-�������\nq - �����\n��� �����: ";

    Dictionary* dictionary = new Dictionary;
    char mode = '\0';

    string enterMessage = "������� ���� ��� ";
    string failMessage = "���� �� ������ � �������!\n";

    while (mode != 'q')
    {
        ShowDictionary(dictionary);
        cout << menu;
        mode = ValidInput<char>();
        ClearTerminal();
        string key;
        string value;

        switch (mode)
        {
            case '1':
            {
                cout << enterMessage << "����������: ";
                key = ValidInput<string>();
                cout << "������� ��������: ";
                value = ValidInput<string>();
                dictionary->Add(key, value);
                break;
            }
            case '2':
            {
                cout << enterMessage << "������: ";
                key = ValidInput<string>();
                value = dictionary->Search(key);

                if (value != "")
                {
                    cout << "���� \"" << key << "\" �������� �������� \"" << value << "\"\n";
                }
                else
                {
                    cout << failMessage;
                }

                break;
            }
            case '3':
            {
                cout << enterMessage << "��������: ";
                key = ValidInput<string>();
                dictionary->Delete(key);
                break;
            }
            case '4':
            {
                ShowHashTable(dictionary);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    delete dictionary;
}

void ShowHashTable(Dictionary* dictionary)
{
    HashTable* hashTable = dictionary->GetHashTable();
    int capacity = hashTable->GetCapacity();
    HashTableItem** data = hashTable->GetData();
    cout << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << "ID " << i << ": " << endl;

        if (data[i])
        {
            HashTableItem* temp = data[i];

            while (temp)
            {
                cout << "\t" << temp->Key << " : " << temp->Value << endl;
                temp = temp->Next;
            }
        }
        else
        {
            cout << "\t***\n";
        }
    }
}

void ShowDictionary(Dictionary* dictionary)
{
    HashTable* hashTable = dictionary->GetHashTable();

    HashTableItem** data = hashTable->GetData();
    int capacity = hashTable->GetCapacity();
    int counter = 0;

    cout << "�������:\t{ ";
    for (int i = 0; i < capacity; i++)
    {
        HashTableItem* temp = data[i];
        string keyStorage = "";

        while (temp)
        {
            if (keyStorage != temp->Key)
            {
                keyStorage = temp->Key;
                counter++;
                if (counter % 3 == 0)
                {
                    cout << "\n->\t\t  ";
                }

                cout << "\"" << temp->Key << "\" : \"" << temp->Value << "\", ";
            }

            temp = temp->Next;
        }
    }
    cout << "\b\b }\n";
}

string GetTypeName(const char* letter)
{
    switch (*letter)
    {
    case 'c':
    {
        return "������";
    }
    case 'i':
    {
        return "����� �����";
    }
    case 'f':
    {
        return "����� � ��������� �������";
    }
    case 'd':
    {
        return "������� �����";
    }
    case 'N':
    {
        return "������";
    }
    default:
    {
        return string("�����������_��� (") + letter + string(")");
    }
    }
}

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;

    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������� ���������� �������� ���� " << 
            GetTypeName(typeid(variable).name()) << ": ";
        cin >> variable;
    }
    return variable;
}

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}
