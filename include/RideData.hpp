#pragma once

enum class ERideStateId
{
    Idle,
    Riding,
    Paused
};

struct RideData
{
    double fCurrentSpeedKmh = 0.0;
    double fAverageSpeedKmh = 0.0;
    double fMaxSpeedKmh = 0.0;
    double fDistanceKm = 0.0;
    unsigned int fPulseCount = 0;
    double fRideTimeSec = 0.0;
    ERideStateId fStateId = ERideStateId::Idle;
};