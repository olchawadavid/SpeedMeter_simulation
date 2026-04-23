#include "NoFilter.hpp"

double NoFilter::apply(double rawSpeedKmh)
{
    return rawSpeedKmh;
}

void NoFilter::reset()
{
}