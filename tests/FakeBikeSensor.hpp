#pragma once

#include "TBikeSensor.hpp"
#include <vector>
#include <cstddef>

class FakeBikeSensor : public TBikeSensor
{
public:
    explicit FakeBikeSensor(const std::vector<double> &pulseTimesSec)
        : fPulseTimesSec(pulseTimesSec),
          fCurrentIndex(0),
          fLastPulseTimeSec(0.0)
    {
    }

    bool isPulseDetected(double currentTimeSec) override
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

    double getPulseTimeSec() const override
    {
        return fLastPulseTimeSec;
    }

private:
    std::vector<double> fPulseTimesSec;
    std::size_t fCurrentIndex;
    double fLastPulseTimeSec;
};