#include "Menu.h"

void PrintBinaryTree(BinaryTreeNode* root, int space = 0, int levelIndent = 5)
{
    if (!root) return;

    space += levelIndent;

    PrintBinaryTree(root->Right, space);

    cout << endl;
    for (int i = levelIndent; i < space; ++i) cout << " ";
    cout << root->Value << endl;

    PrintBinaryTree(root->Left, space);
}

void PrintTreap(TreapNode* current, int space = 0, int levelIndent = 5)
{
    if (!current) return;

    space += levelIndent;

    PrintTreap(current->Right, space, levelIndent);

    cout << endl;
    for (int i = levelIndent; i < space; ++i) cout << " ";
    cout << current->Key << "(" << current->Priority << ")";

    PrintTreap(current->Left, space, levelIndent);
}

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

void ShowMenu()
{
    int choice;

    do
    {
        cout << "Выберите СД для работы\n";
        cout << "1. Бинарное дерево.\n";
        cout << "2. Декартовое дерево.\n";
        cout << "0. Выход.\n";

        choice = GetIntegerInput();

        switch (choice)
        {
        case 1:
        {
            ShowBinaryTreeMenu();
            break;
        }
        case 2:
        {
            ShowTreapMenu();
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
}

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}

void ShowBinaryTreeMenu() 
{
    int choice;
    int value;
    BinaryTree* bt = new BinaryTree();
    BinaryTreeNode* btn;

    do
    {
        std::cout << "Работа с бинарным деревом. Ваше действие: " << endl;
        std::cout << "1 - Добавить элемент.  " << endl;
        std::cout << "2 - Удалить элемент. " << endl;
        std::cout << "3 - Найти элемент. " << endl;
        std::cout << "4 - Вывести минимум. " << endl;
        std::cout << "5 - Вывести максимум. " << endl;
        std::cout << "6 - Вывести дерево. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для добавления: " << endl;

                value = GetIntegerInput();

                bt->Add(value);

                std::cout << "Элемент добавлен!" << endl;
                break;
            }
            case 2:
            {
                std::cout << "Введите элемент для удаления: " << endl;

                value = GetIntegerInput();

                bt->Remove(value);

                std::cout << "Элемент удалён." << endl;
                break;
            }
            case 3:
            {
                std::cout << "Введите элемент для поиска: " << endl;

                value = GetIntegerInput();

                btn = bt->Search(value);

                if (btn != nullptr) 
                {
                    std::cout << "Элемент найден!" << endl;
                }
                else
                {
                    std::cout << "Данного элемента нет в дереве. " << endl;
                }

                break;
            }
            case 4:
            {
                try 
                { 
                    std::cout << "Минимальный элемент: "<< bt->FindMin() << endl;
                }
                catch (runtime_error)
                {
                    std::cout << "Дерево пусто!" << endl;
                }
                break;
            }
            case 5:
            {
                try
                {
                    std::cout << "Максимальный элемент: " << bt->FindMax() << endl;
                }
                catch (runtime_error)
                {
                    std::cout << "Дерево пусто!" << endl;
                }
            break;
            }
            case 6:
            {
                std::cout << "Бинароное дерево: " << endl;
                PrintBinaryTree(bt->GetRoot());
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "Введите корректное значение! " << endl;
                break;
            }
        }

        cout << endl;
    } while (choice != 0);

    ClearTerminal();
    delete bt;
}

void ShowTreapMenu() 
{
    int choice;
    int value;
    Treap* treap = new Treap();
    TreapNode* treapNode;

    do
    {
        std::cout << "Работа с декартовым деревом. Ваше действие: " << endl;
        std::cout << "1 - Добавить элемент (опт).  " << endl;
        std::cout << "2 - Добавить элемент (не опт.).  " << endl;
        std::cout << "3 - Удалить элемент (опт). " << endl;
        std::cout << "4 - Удалить элемент ( неопт). " << endl;
        std::cout << "5 - Найти элемент. " << endl;
        std::cout << "6 - Вывести дерево. " << endl;
        std::cout << "0 - Выход. " << endl;

        choice = GetIntegerInput();

        switch (choice)
        {
            case 1:
            {
                std::cout << "Введите элемент для добавления: " << endl;

                value = GetIntegerInput();

                treap->AddOptimized(value);

                std::cout << "Элемент добавлен!" << endl;
                break;
            }
            case 2:
            {
                std::cout << "Введите элемент для добавления: " << endl;

                value = GetIntegerInput();

                treap->AddUnoptimized(value);

                std::cout << "Элемент добавлен!" << endl;
                break;
            }
            case 3:
            {
                std::cout << "Введите элемент для удаления: " << endl;

                value = GetIntegerInput();

                treap->RemoveOptimized(value);

                std::cout << "Элемент удалён!" << endl;
                break;
            }
            case 4:
            {
                std::cout << "Введите элемент для удаления: " << endl;

                value = GetIntegerInput();

                treap->RemoveUnoptimized(value);

                std::cout << "Элемент удалён!" << endl;
                break;
            }
            case 5:
            {
                std::cout << "Введите элемент для поиска: " << endl;

                value = GetIntegerInput();

                treapNode = treap->Search(value);

                if (treapNode != nullptr)
                {
                    std::cout << "Элемент найден!" << endl;
                }
                else
                {
                    std::cout << "Данного элемента нет в дереве. " << endl;
                }

                break;
            }
            case 6:
            {
                std::cout << "Декартово дерево: " << endl;
                PrintTreap(treap->GetRoot());
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                std::cout << "Введите корректное значение! " << endl;
                break;
            }
        }

        cout << endl;
    } while (choice != 0);

    ClearTerminal();
    delete treap;
};
