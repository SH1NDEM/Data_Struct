#include <stdexcept>
#include "DynamicArray.h"



void DynamicArray:: IncreaseSize()
{
    _capacity *= _growthFactor;
    int* newArray = new int[_capacity];
    for (int i = 0; i < _size; ++i)
    {
        newArray[i] = _array[i];
    }

    delete[] _array;
    _array = newArray;
}

void DynamicArray::ReduceSize()
{
    if (_capacity > 8) 
    {
        _capacity = _capacity / _growthFactor;
        int* newArray = new int[_capacity];

        for (int i = 0; i < _size; i++)
        {
            newArray[i] = _array[i];
        }

        delete[] _array;
        _array = newArray;
    }
}

DynamicArray::DynamicArray() : _size(0), _capacity(8)
{
    _array = new int[_capacity];
}

DynamicArray:: ~DynamicArray()
{
    delete[] _array;
}

int DynamicArray::GetSize()
{
    return _size;
}

int DynamicArray::GetCapacity()
{
    return _capacity;
}

int* DynamicArray::GetArray()
{
    return _array;
}

void DynamicArray::IfArrayFull() 
{
    if (_size == _capacity)
    {
        IncreaseSize();
    }
}

void DynamicArray::AddElementAtStart(int value)
{
    // TODO: дубли +
    IfArrayFull();

    for (int i = _size; i > 0; i--)
    {
        _array[i] = _array[i - 1];
    }

    _array[0] = value;
    _size++;
}

void DynamicArray::AddElementAtEnd(int value)
{
    IfArrayFull();

    _array[_size] = value;
    _size++;
}

void DynamicArray::AddElementByIndex(int index, int value)
{
    if (index < 0 || index > _size) 
    {
        throw std::out_of_range("Index out of range");
    }

    IfArrayFull();

    for (int i = _size; i > index; --i)
    {
        _array[i] = _array[i - 1];
    }

    _array[index] = value;
    _size++;
}
// TODO: RSDN +
void DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size) 
    {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < _size - 1; ++i)
    {
        _array[i] = _array[i + 1];
    }

    _size--;

    if (_size < _capacity / _growthFactor)
    {
        ReduceSize();
    }
}

void DynamicArray::RemoveByValue(int value)
{
    // TODO: неявная поведение функции + 
    // теперь данная функция удаляет перое вхождение элемента по значению и прекращает работу
    for (int i = 0; i < _size; ++i)
    {
        if (_array[i] == value)
        {
            RemoveByIndex(i);
            --_size;
            break;
        }
    }
}

// TODO: RSDN +
int DynamicArray::GetElement(int index)
{
    if (index < 0 || index >= _size) 
    {
        throw std::out_of_range("Index out of range");
    }

    return _array[index];
}

void DynamicArray::SortArray()
{
    bool swapped = true;
    int left = 0;
    int right = _size - 1;
    int temp;

    while (swapped)
    {
        swapped = false;

        for (int i = left; i < right; i++)
        {
            if (_array[i] > _array[i + 1])
            {
                temp = _array[i];
                _array[i] = _array[i + 1];
                _array[i + 1] = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (_array[i] < _array[i - 1])
            {
                temp = _array[i];
                _array[i] = _array[i - 1];
                _array[i - 1] = temp;
                swapped = true;
            }
        }
        left++;
    }
}


// TODO: RSDN +
int DynamicArray::LinearSearch(int value)
{
    for (int i = 0; i < _size; i++)
    {
        if (_array[i] == value) { return i; }
    }

    return -1; 
}

// TODO: RSDN +
int DynamicArray::BinarySearch(int value)
{
    SortArray();

    int left = 0;
    int right = _size;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (_array[mid] == value) 
        {
            return mid; 
        }

        if (_array[mid] < value) 
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return -1; 
}

