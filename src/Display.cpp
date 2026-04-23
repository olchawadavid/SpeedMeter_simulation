#include "Display.hpp"
#include <iostream>
#include <iomanip>

namespace
{
    const char *toText(ERideStateId stateId)
    {
        switch (stateId)
        {
        case ERideStateId::Idle:
            return "Idle";
        case ERideStateId::Riding:
            return "Riding";
        case ERideStateId::Paused:
            return "Paused";
        default:
            return "Unknown";
        }
    }
}

void Display::onRideDataUpdated(const RideData &rideData)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout
        << "[DISPLAY] "
        << "Stan: " << toText(rideData.fStateId)
        << " | Predkosc: " << rideData.fCurrentSpeedKmh << " km/h"
        << " | Srednia: " << rideData.fAverageSpeedKmh << " km/h"
        << " | Max: " << rideData.fMaxSpeedKmh << " km/h"
        << " | Dystans: " << rideData.fDistanceKm << " km"
        << " | Czas: " << rideData.fRideTimeSec << " s"
        << " | Impulsy: " << rideData.fPulseCount
        << '\n';
}