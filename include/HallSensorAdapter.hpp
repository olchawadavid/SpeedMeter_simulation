#pragma once

#include "TBikeSensor.hpp"
#include <cstddef>
#include <vector>

class HallSensorAdapter : public TBikeSensor
{
public:
    HallSensorAdapter();

    bool isPulseDetected(double currentTimeSec) override;
    double getPulseTimeSec() const override;

private:
    std::vector<double> fPulseTimesSec;
    std::size_t fCurrentIndex;
    double fLastPulseTimeSec;
};