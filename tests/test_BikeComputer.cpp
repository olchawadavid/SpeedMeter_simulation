#include <gtest/gtest.h>
#include "BikeComputer.hpp"
#include "NoFilter.hpp"
#include "IdleState.hpp"
#include "RidingState.hpp"
#include "PausedState.hpp"
#include "FakeBikeSensor.hpp"

TEST(BikeComputerTest, FirstPulseIncreasesPulseCountAndDistance)
{
    FakeBikeSensor sensor({0.5});
    NoFilter filter;
    BikeComputer bikeComputer(&sensor, &filter);

    bikeComputer.updateFromSensor(0.5);

    EXPECT_EQ(bikeComputer.getRideData().fPulseCount, 1u);
    EXPECT_NEAR(bikeComputer.getRideData().fDistanceKm, 0.0021, 1e-6);
    EXPECT_DOUBLE_EQ(bikeComputer.getRideData().fCurrentSpeedKmh, 0.0);
}

TEST(BikeComputerTest, SecondPulseCalculatesSpeed)
{
    FakeBikeSensor sensor({0.5, 1.0});
    NoFilter filter;
    BikeComputer bikeComputer(&sensor, &filter);

    bikeComputer.updateFromSensor(0.5);
    bikeComputer.updateFromSensor(1.0);

    EXPECT_EQ(bikeComputer.getRideData().fPulseCount, 2u);
    EXPECT_NEAR(bikeComputer.getRideData().fCurrentSpeedKmh, 15.12, 0.01);
    EXPECT_NEAR(bikeComputer.getRideData().fMaxSpeedKmh, 15.12, 0.01);
}

TEST(BikeComputerTest, AverageSpeedIsCalculated)
{
    FakeBikeSensor sensor({0.5, 1.0});
    NoFilter filter;
    BikeComputer bikeComputer(&sensor, &filter);

    bikeComputer.updateFromSensor(0.5);
    bikeComputer.updateFromSensor(1.0);

    EXPECT_GT(bikeComputer.getRideData().fAverageSpeedKmh, 0.0);
}