#include "QueueRing.h"

QueueRing::QueueRing()
{
    _sizeBuffer = DefoltSize;
    _ringBuffer = new RingBuffer(_sizeBuffer);
}

QueueRing::~QueueRing()
{
    delete _ringBuffer;
}

void QueueRing::ResizeBuffer(const float& growthFactor)
{
    _sizeBuffer *= growthFactor;
    RingBuffer* newBuffer = new RingBuffer(_sizeBuffer);

    int occupiedSpace = _ringBuffer->GetUsedSize();
    for (int i = 0; i < occupiedSpace; i++)
    {
        newBuffer->Push(_ringBuffer->Pop());
    }

    delete _ringBuffer;
    _ringBuffer = newBuffer;
}

void QueueRing::Enqueue(const int& value)
{
    if (!_ringBuffer->GetFreeSpace())
    {
        ResizeBuffer(GrownFactor);
    }

    _ringBuffer->Push(value);
}

int QueueRing::Dequeue()
{
    int result = _ringBuffer->Pop();
    bool ResizeCondition = _ringBuffer->GetFreeSpace() <= _ringBuffer->GetSize() / GrownFactor;
    ResizeCondition &= _ringBuffer->GetFreeSpace() >= 4;

    if (ResizeCondition)
    {
        ResizeBuffer(1/GrownFactor);
    }

    return result;
}