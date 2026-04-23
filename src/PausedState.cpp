#include "PausedState.hpp"
#include "BikeComputer.hpp"

void PausedState::handle(BikeComputer &bikeComputer, double currentTimeSec)
{
    (void)currentTimeSec;

    RideData &rideData = bikeComputer.getRideData();
    rideData.fStateId = ERideStateId::Paused;
    rideData.fCurrentSpeedKmh = 0.0;
}

const char *PausedState::getName() const
{
    return "Paused";
}