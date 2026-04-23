#pragma once

#include "TRideState.hpp"

class IdleState : public TRideState
{
public:
    void handle(BikeComputer &bikeComputer, double currentTimeSec) override;
    const char *getName() const override;
};