
#include "gtest/gtest.h"

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

