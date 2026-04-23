#include "IdleState.hpp"
#include "BikeComputer.hpp"

void IdleState::handle(BikeComputer &bikeComputer, double currentTimeSec)
{
    (void)currentTimeSec;

    RideData &rideData = bikeComputer.getRideData();
    rideData.fStateId = ERideStateId::Idle;
    rideData.fCurrentSpeedKmh = 0.0;
}

const char *IdleState::getName() const
{
    return "Idle";
}