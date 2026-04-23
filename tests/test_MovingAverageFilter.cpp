#include <gtest/gtest.h>
#include "MovingAverageFilter.hpp"

TEST(MovingAverageFilterTest, ReturnsSingleSampleForFirstValue)
{
    MovingAverageFilter filter;
    EXPECT_DOUBLE_EQ(filter.apply(10.0), 10.0);
}

TEST(MovingAverageFilterTest, CalculatesAverageCorrectly)
{
    MovingAverageFilter filter;

    EXPECT_DOUBLE_EQ(filter.apply(10.0), 10.0);
    EXPECT_DOUBLE_EQ(filter.apply(20.0), 15.0);
    EXPECT_DOUBLE_EQ(filter.apply(30.0), 20.0);
    EXPECT_DOUBLE_EQ(filter.apply(40.0), 25.0);
}

TEST(MovingAverageFilterTest, DropsOldestSampleAfterBufferIsFull)
{
    MovingAverageFilter filter;

    filter.apply(10.0);
    filter.apply(20.0);
    filter.apply(30.0);
    filter.apply(40.0);

    EXPECT_DOUBLE_EQ(filter.apply(50.0), 35.0); // średnia z 20,30,40,50
}