#pragma once

class BikeComputer;

class TRideState
{
public:
    virtual ~TRideState() = default;

    virtual void handle(BikeComputer &bikeComputer, double currentTimeSec) = 0;
    virtual const char *getName() const = 0;
};