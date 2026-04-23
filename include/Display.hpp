#pragma once

#include "TObserver.hpp"

class Display : public TObserver
{
public:
    void onRideDataUpdated(const RideData &rideData) override;
};