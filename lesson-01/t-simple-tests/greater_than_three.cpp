
#include "gtest/gtest.h"

bool greater_than_three(int n)
{
  return false; // TODO
}

TEST(greater_than_three, false_with_zero)
{
  EXPECT_EQ(false, greater_than_three(0));
}

TEST(greater_than_three, false_with_three)
{
  EXPECT_EQ(false, greater_than_three(3));
}

TEST(greater_than_three, true_with_five)
{
  EXPECT_EQ(true, greater_than_three(5));
}

