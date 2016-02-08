
#include "gtest/gtest.h"

// megkeresi a legkisebb n-t, amire -2^n <= i <= 2^n
int symmetric_power_range(int i)
{
  int n = 0;
  int pow_pos =  1;
  int pow_neg = -1;

  while(pow_pos < i && pow_neg > i)
    pow_pos *= 2;
    pow_neg *= 2;
    n++;

  return n;
}

TEST(symmetric_power_range, zero_for_one)
{
  EXPECT_EQ(0, symmetric_power_range(1));
}

TEST(symmetric_power_range, zero_for_minus_one)
{
  EXPECT_EQ(0, symmetric_power_range(-1));
}

TEST(symmetric_power_range, four_for_14)
{
  EXPECT_EQ(4, symmetric_power_range(14));
}

TEST(symmetric_power_range, four_for_minus_14)
{
  EXPECT_EQ(4, symmetric_power_range(-14));
}

