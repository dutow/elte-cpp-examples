
#include "gtest/gtest.h"

int sum_dividible_by_seven(int min, int max)
{
  int sum = 0;
  for(int i=min; i<=max; ++i)
  {
    if(i % 7 == 0)
    {
      sum += i;
    }
  }

  return sum;
}

TEST(sum_dividible_by_seven, empty_interval_is_zero)
{
  EXPECT_EQ(0, sum_dividible_by_seven(0,0));
}

TEST(sum_dividible_by_seven, interval_without_anything_matching)
{
  EXPECT_EQ(0, sum_dividible_by_seven(0,6));
}

TEST(sum_dividible_by_seven, just_14)
{
  EXPECT_EQ(14, sum_dividible_by_seven(14,14));
}

TEST(sum_dividible_by_seven, just_14_21)
{
  EXPECT_EQ(35, sum_dividible_by_seven(14,21));
}
