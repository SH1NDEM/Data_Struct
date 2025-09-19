#include "QueueStack.h"
#include "Stack.h"

QueueStack::QueueStack()
{
    _stackIn = new Stack(DefoltSize);
    _stackOut = new Stack(DefoltSize);
}

QueueStack::~QueueStack()
{
    delete _stackIn;
    delete _stackOut;
}

void QueueStack::Enqueue(const int& value)
{
    _stackIn->Push(value);
}

int QueueStack::Dequeue()
{
    if (_stackOut->IsEmpty())
    {
        if (!_stackIn->IsEmpty())
        {
            while (!_stackIn->IsEmpty())
            {
                _stackOut->Push(_stackIn->Pop());
            }
        }
        else
        {
            return 0;
        }
    }

    int result = _stackOut->Pop();
    return result;
}

void QueueStack::Resize(int newSize) 
{
    _stackIn->Resize(newSize);
    _stackOut->Resize(newSize);
}