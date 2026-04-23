#include "MovingAverageFilter.hpp"

MovingAverageFilter::MovingAverageFilter()
    : fIndex(0),
      fCount(0)
{
    reset();
}

double MovingAverageFilter::apply(double rawSpeedKmh)
{
    fBuffer[fIndex] = rawSpeedKmh;
    fIndex = (fIndex + 1) % kBufferSize;

    if (fCount < kBufferSize)
    {
        ++fCount;
    }

    double sum = 0.0;
    for (int i = 0; i < fCount; ++i)
    {
        sum += fBuffer[i];
    }

    return (fCount > 0) ? (sum / fCount) : 0.0;
}

void MovingAverageFilter::reset()
{
    for (int i = 0; i < kBufferSize; ++i)
    {
        fBuffer[i] = 0.0;
    }

    fIndex = 0;
    fCount = 0;
}