#pragma once

#include "TBikeSensor.hpp"
#include "TSpeedFilter.hpp"
#include "TObserver.hpp"
#include "TRideState.hpp"
#include "RideData.hpp"

class BikeComputer
{
public:
    BikeComputer(TBikeSensor *sensor, TSpeedFilter *filter);

    void updateFromSensor(double currentTimeSec);
    void applyCurrentState(double currentTimeSec);
    void addObserver(TObserver *observer);
    void notifyObservers() const;
    void setState(TRideState *state);

    RideData &getRideData();
    const RideData &getRideData() const;

    double getLastPulseTimeSec() const;
    bool hasLastPulse() const;
    double getPausedThresholdSec() const;
    const char *getStateName() const;

private:
    void processPulse(double pulseTimeSec);
    void updateAverageSpeedKmh();

private:
    static constexpr int kMaxObservers = 5;
    static constexpr double kDefaultWheelCircumferenceM = 2.10;
    static constexpr double kDefaultPausedThresholdSec = 2.0;

    TBikeSensor *fSensor;
    TSpeedFilter *fFilter;
    TRideState *fCurrentState;

    RideData fRideData;

    TObserver *fObservers[kMaxObservers];
    int fObserverCount;

    double fWheelCircumferenceM;
    double fLastPulseTimeSec;
    bool fHasLastPulse;
    double fPausedThresholdSec;
};