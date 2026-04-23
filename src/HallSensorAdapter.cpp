#include "HallSensorAdapter.hpp"

HallSensorAdapter::HallSensorAdapter()
    : fCurrentIndex(0),
      fLastPulseTimeSec(0.0)
{
    double currentPulseTimeSec = 0.0;

    // Około 15 km/h
    for (int i = 0; i < 10; ++i)
    {
        currentPulseTimeSec += 0.50;
        fPulseTimesSec.push_back(currentPulseTimeSec);
    }

    // Około 20 km/h
    for (int i = 0; i < 10; ++i)
    {
        currentPulseTimeSec += 0.38;
        fPulseTimesSec.push_back(currentPulseTimeSec);
    }

    // Około 10 km/h
    for (int i = 0; i < 8; ++i)
    {
        currentPulseTimeSec += 0.75;
        fPulseTimesSec.push_back(currentPulseTimeSec);
    }
}

bool HallSensorAdapter::isPulseDetected(double currentTimeSec)
{
    if (fCurrentIndex >= fPulseTimesSec.size())
    {
        return false;
    }

    if (fPulseTimesSec[fCurrentIndex] <= currentTimeSec)
    {
        fLastPulseTimeSec = fPulseTimesSec[fCurrentIndex];
        ++fCurrentIndex;
        return true;
    }

    return false;
}

double HallSensorAdapter::getPulseTimeSec() const
{
    return fLastPulseTimeSec;
}