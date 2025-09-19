#include <stdexcept>
#include "RingBuffer.h"

using namespace std;

RingBuffer::RingBuffer(int size) : _size(size), _head(0), _tail(0), _isFull(false)
{
    _buffer = new int[size];
}

RingBuffer::~RingBuffer()
{
    delete _buffer;
}

void RingBuffer:: Push(int value) 
{
    _buffer[_head] = value;

    if (_isFull)
    {
        _tail = (_tail + 1) % _size; 
    }

    _head = (_head + 1) % _size; 
    _isFull = _head == _tail;
}

int RingBuffer::Pop() 
{
    if (IsEmpty()) 
    {
        throw std::exception("Buffer is empty");
    }

    int value = _buffer[_tail];
    _isFull = false;
    _tail = (_tail + 1) % _size; 

    return value;
}

bool RingBuffer::IsEmpty() const 
{
    return (!_isFull && (_head == _tail));
}

int RingBuffer::GetSize() const 
{
    return _size;
}

int RingBuffer::GetUsedSize() const
{
    if (_isFull)
    {
        return _size;
    }

    if (_head >= _tail)
    {
        return _head - _tail;
    }

    return _size + _head - _tail;
}


int RingBuffer::GetFreeSpace() const
{
    if (_head == -1)
    {
        return _size;
    }

    return _size - GetUsedSize();
}

void RingBuffer::Resize(int newSize)
{
    if (newSize == 0)
    {
        throw std::invalid_argument("New size must be greater than 0");
    }

    int* newBuffer = new int[newSize];
    int usedSize = GetUsedSize();

   
    for (size_t i = 0; i < std::min(usedSize, newSize); ++i)
    {
        newBuffer[i] = _buffer[(_tail + i) % _size];
    }

    delete[] _buffer; 
    _buffer = newBuffer; 
    _size = newSize; 
    _head = (usedSize < newSize) ? usedSize : newSize;
    _tail = 0;
    _isFull = (usedSize == newSize);
};


