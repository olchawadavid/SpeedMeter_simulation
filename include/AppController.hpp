#pragma once

#include "HallSensorAdapter.hpp"
#include "MovingAverageFilter.hpp"
#include "Display.hpp"
#include "Logger.hpp"
#include "IdleState.hpp"
#include "RidingState.hpp"
#include "PausedState.hpp"
#include "BikeComputer.hpp"

class AppController
{
public:
    AppController();
    void run();

private:
    void updateState(double currentTimeSec);

private:
    static constexpr double kSimulationStepSec = 0.25;
    static constexpr double kSimulationDurationSec = 18.0;

    HallSensorAdapter fSensor;
    MovingAverageFilter fFilter;
    Display fDisplay;
    Logger fLogger;

    IdleState fIdleState;
    RidingState fRidingState;
    PausedState fPausedState;

    BikeComputer fBikeComputer;
};