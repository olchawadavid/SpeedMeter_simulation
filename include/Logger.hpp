#pragma once

#include "TObserver.hpp"

class Logger : public TObserver
{
public:
    void onRideDataUpdated(const RideData &rideData) override;
};