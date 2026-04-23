#pragma once

/*Wzorzec*/
class TBikeSensor
{
public:
    virtual ~TBikeSensor() = default;

    virtual bool isPulseDetected(double currentTimeSec) = 0;
    virtual double getPulseTimeSec() const = 0;
};