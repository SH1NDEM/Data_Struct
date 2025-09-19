#pragma once
#include "TreapNode.h"

//! \brief Класс для представления дерева Treap.
class Treap
{
private:
    //! \brief Указатель на корневой узел дерева Treap.
    TreapNode* _root;

    //! \brief Разделяет дерево на два поддерева по заданному ключу.
    //! \param current Текущий узел.
    //! \param key Ключ для разделения.
    //! \param left Указатель на левое поддерево (результат).
    //! \param right Указатель на правое поддерево (результат).
    void Split(TreapNode* current, int key, TreapNode*& left, TreapNode*& right);

    //! \brief Объединяет два дерева Treap в одно.
    //! \param left Левое поддерево.
    //! \param right Правое поддерево.
    //! \return Указатель на новое объединённое дерево.
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief Оптимизированное добавление узла в дерево Treap.
    //! \param current Текущий узел.
    //! \param key Ключ для добавления.
    //! \return Указатель на корневой узел после добавления.
    TreapNode* AddOptimized(TreapNode* current, int key);

    //! \brief Оптимизированное удаление узла из дерева Treap.
    //! \param current Текущий узел.
    //! \param key Ключ для удаления.
    //! \return Указатель на корневой узел после удаления.
    TreapNode* RemoveOptimized(TreapNode* current, int key);

    //! \brief Поиск узла с заданным значением.
    //! \param node Узел, с которого начинается поиск.
    //! \param data Значение для поиска.
    //! \return Указатель на найденный узел или nullptr, если узел не найден.
    TreapNode* Search(TreapNode* node, int data);

    //! \brief Очистка дерева, освобождение памяти.
    //! \param current Текущий узел для очистки.
    void Clear(TreapNode* current);

public:
    //! \brief Конструктор. Создает пустое дерево Treap.
    Treap();

    //! \brief Деструктор. Удаляет все узлы дерева Treap.
    ~Treap();

    //! \brief Неоптимизированное добавление узла в дерево.
    //! \param key Ключ для добавления.
    void AddUnoptimized(int key);

    //! \brief Неоптимизированное удаление узла из дерева.
    //! \param key Ключ для удаления.
    void RemoveUnoptimized(int key);

    //! \brief Оптимизированное добавление узла в дерево.
    //! \param key Ключ для добавления.
    void AddOptimized(int key);

    //! \brief Оптимизированное удаление узла из дерева.
    //! \param key Ключ для удаления.
    void RemoveOptimized(int key);

    //! \brief Поиск узла с заданным значением.
    //! \param data Значение для поиска.
    //! \return Указатель на найденный узел или nullptr, если узел не найден.
    TreapNode* Search(int data);

    //! \brief Получение корневого узла дерева.
    //! \return Указатель на корневой узел.
    TreapNode* GetRoot();
};
