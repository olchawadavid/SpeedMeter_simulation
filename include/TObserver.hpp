#pragma once

#include "RideData.hpp"

class TObserver
{
public:
    virtual ~TObserver() = default;

    virtual void onRideDataUpdated(const RideData &rideData) = 0;
};