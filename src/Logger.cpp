#include "Logger.hpp"
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

void Logger::onRideDataUpdated(const RideData &rideData)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout
        << "[LOGGER] "
        << "state=" << toText(rideData.fStateId)
        << ", speed=" << rideData.fCurrentSpeedKmh
        << ", distance=" << rideData.fDistanceKm
        << ", pulses=" << rideData.fPulseCount
        << '\n';
}