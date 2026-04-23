#pragma once

#include "TSpeedFilter.hpp"

class MovingAverageFilter : public TSpeedFilter
{
public:
    MovingAverageFilter();
    double apply(double rawSpeedKmh) override;
    void reset() override;

private:
    static constexpr int kBufferSize = 4;

    double fBuffer[kBufferSize];
    int fIndex;
    int fCount;
};