#include <stdexcept>
#include "Stack.h"


Stack::Stack(int bufferSize) : _top(-1)
{
	_size = bufferSize;
	_buffer = new int[bufferSize];
}

Stack::~Stack() 
{
	delete[] _buffer;
}

void Stack::Resize(int newSize)
{
	if (newSize <= 0) 
	{
		throw std::invalid_argument("Неправильный размер стека.");
	}

	int* newBuffer = new int[newSize];
	
	if (newSize >= _size) 
	{
		for (int i = 0; i < _size; i++) 
		{
			newBuffer[i] = _buffer[i];
		}
	}
	else 
	{
		for (int i = 0; i < newSize;i++) 
		{
			newBuffer[i] = _buffer[i];
		}
	}

	delete[] _buffer;
	_buffer = newBuffer;
	_size = newSize;
}

bool Stack::IsEmpty() 
{
	return _top == -1;
}


void Stack::Push(int value) 
{
	if (_size - 1 > _top) 
	{
		_top++;
		_buffer[_top] = value;
	}
	else 
	{
		throw std::exception("Стек переполнен");
	}
}

int Stack::Pop() 
{
	if (IsEmpty()) 
	{
		return -1;
	}
	else 
	{

		return _buffer[_top--];	
	}
}
