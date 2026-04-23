#include "RidingState.hpp"
#include "BikeComputer.hpp"

void RidingState::handle(BikeComputer &bikeComputer, double currentTimeSec)
{
    (void)currentTimeSec;

    RideData &rideData = bikeComputer.getRideData();
    rideData.fStateId = ERideStateId::Riding;
}

const char *RidingState::getName() const
{
    return "Riding";
}