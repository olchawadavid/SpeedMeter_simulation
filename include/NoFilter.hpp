#pragma once

#include "TSpeedFilter.hpp"

class NoFilter : public TSpeedFilter
{
public:
    double apply(double rawSpeedKmh) override;
    void reset() override;
};