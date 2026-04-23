#include "BikeComputer.hpp"

BikeComputer::BikeComputer(TBikeSensor *sensor, TSpeedFilter *filter)
    : fSensor(sensor),
      fFilter(filter),
      fCurrentState(nullptr),
      fObserverCount(0),
      fWheelCircumferenceM(kDefaultWheelCircumferenceM),
      fLastPulseTimeSec(0.0),
      fHasLastPulse(false),
      fPausedThresholdSec(kDefaultPausedThresholdSec)
{
    for (int i = 0; i < kMaxObservers; ++i)
    {
        fObservers[i] = nullptr;
    }
}

void BikeComputer::updateFromSensor(double currentTimeSec)
{
    while (fSensor->isPulseDetected(currentTimeSec))
    {
        processPulse(fSensor->getPulseTimeSec());
    }
}

void BikeComputer::applyCurrentState(double currentTimeSec)
{
    if (fCurrentState != nullptr)
    {
        fCurrentState->handle(*this, currentTimeSec);
    }
}

void BikeComputer::processPulse(double pulseTimeSec)
{
    ++fRideData.fPulseCount;
    fRideData.fDistanceKm += fWheelCircumferenceM / 1000.0;

    if (fHasLastPulse)
    {
        const double deltaTimeSec = pulseTimeSec - fLastPulseTimeSec;

        if (deltaTimeSec > 0.0)
        {
            const double rawSpeedKmh = (fWheelCircumferenceM / deltaTimeSec) * 3.6;
            fRideData.fCurrentSpeedKmh = fFilter->apply(rawSpeedKmh);

            if (fRideData.fCurrentSpeedKmh > fRideData.fMaxSpeedKmh)
            {
                fRideData.fMaxSpeedKmh = fRideData.fCurrentSpeedKmh;
            }
        }
    }

    fLastPulseTimeSec = pulseTimeSec;
    fHasLastPulse = true;

    fRideData.fRideTimeSec = pulseTimeSec;
    updateAverageSpeedKmh();
}

void BikeComputer::updateAverageSpeedKmh()
{
    if (fRideData.fRideTimeSec > 0.0)
    {
        fRideData.fAverageSpeedKmh = fRideData.fDistanceKm / (fRideData.fRideTimeSec / 3600.0);
    }
    else
    {
        fRideData.fAverageSpeedKmh = 0.0;
    }
}

void BikeComputer::addObserver(TObserver *observer)
{
    if (fObserverCount < kMaxObservers)
    {
        fObservers[fObserverCount] = observer;
        ++fObserverCount;
    }
}

void BikeComputer::notifyObservers() const
{
    for (int i = 0; i < fObserverCount; ++i)
    {
        if (fObservers[i] != nullptr)
        {
            fObservers[i]->onRideDataUpdated(fRideData);
        }
    }
}

void BikeComputer::setState(TRideState *state)
{
    fCurrentState = state;
}

RideData &BikeComputer::getRideData()
{
    return fRideData;
}

const RideData &BikeComputer::getRideData() const
{
    return fRideData;
}

double BikeComputer::getLastPulseTimeSec() const
{
    return fLastPulseTimeSec;
}

bool BikeComputer::hasLastPulse() const
{
    return fHasLastPulse;
}

double BikeComputer::getPausedThresholdSec() const
{
    return fPausedThresholdSec;
}

const char *BikeComputer::getStateName() const
{
    if (fCurrentState != nullptr)
    {
        return fCurrentState->getName();
    }

    return "NoState";
}