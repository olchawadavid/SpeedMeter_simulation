#pragma once

class TSpeedFilter
{
public:
    virtual ~TSpeedFilter() = default;

    virtual double apply(double rawSpeedKmh) = 0;
    virtual void reset() = 0;
};