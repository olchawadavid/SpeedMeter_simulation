#include "AppController.hpp"
#include <iostream>

AppController::AppController()
    : fSensor(),
      fFilter(),
      fDisplay(),
      fLogger(),
      fIdleState(),
      fRidingState(),
      fPausedState(),
      fBikeComputer(&fSensor, &fFilter)
{
    fBikeComputer.addObserver(&fDisplay);
    fBikeComputer.addObserver(&fLogger);
    fBikeComputer.setState(&fIdleState);
}

void AppController::updateState(double currentTimeSec)
{
    if (!fBikeComputer.hasLastPulse())
    {
        fBikeComputer.setState(&fIdleState);
        return;
    }

    const double deltaTimeSec = currentTimeSec - fBikeComputer.getLastPulseTimeSec();

    if (deltaTimeSec <= fBikeComputer.getPausedThresholdSec())
    {
        fBikeComputer.setState(&fRidingState);
    }
    else
    {
        fBikeComputer.setState(&fPausedState);
    }
}

void AppController::run()
{
    std::cout << "Start symulacji licznika rowerowego\n\n";

    for (double currentTimeSec = 0.0;
         currentTimeSec <= kSimulationDurationSec;
         currentTimeSec += kSimulationStepSec)
    {

        fBikeComputer.updateFromSensor(currentTimeSec);
        updateState(currentTimeSec);
        fBikeComputer.applyCurrentState(currentTimeSec);
        fBikeComputer.notifyObservers();

        std::cout << "[APP] Stan obiektu BikeComputer: "
                  << fBikeComputer.getStateName()
                  << "\n\n";
    }
}