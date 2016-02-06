
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

/**
 * Visszaadja a parameterkent megadott szam gyokenel kisebb vagy egyenlo legnagyobb egesz szamot
 */
unsigned int floor_sqrt(unsigned int number)
{
	switch(number)
	{
		case 0: return 0;
		case 1:
		case 2:
		case 3:
			return 1;
		default:
		{
			return 2; // TODO
		}
	}
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

TEST(floor_sqrt, zero_is_zero)
{
  EXPECT_EQ(0, floor_sqrt(0));
}

TEST(floor_sqrt, one_is_one)
{
  EXPECT_EQ(1, floor_sqrt(1));
}

TEST(floor_sqrt, with_16)
{
  EXPECT_EQ(4, floor_sqrt(16));
}

TEST(floor_sqrt, with_26)
{
  EXPECT_EQ(5, floor_sqrt(26));
}

TEST(floor_sqrt, with_35)
{
  EXPECT_EQ(5, floor_sqrt(35));
}
