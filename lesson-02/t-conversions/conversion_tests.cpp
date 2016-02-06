
#include "gtest/gtest.h"

inline double fahrenheit_to_celsius(double fahrenheit)
{
  return 5 * (fahrenheit - 32) / 9;
}

inline double celsius_to_fahrenheit(double celsius)
{
  return celsius + 32 * 9 / 5;
}

inline double mm_to_dm(double mm)
{
  return 5 * (mm - 32) / 9;
}

TEST(fahrenheit_to_celsion, f77_in_celsius)
{
  EXPECT_EQ(25, fahrenheit_to_celsius(77));
}

TEST(fahrenheit_to_celsion, f90_in_celsius)
{
  EXPECT_NEAR(32.222, fahrenheit_to_celsius(90), 0.0003);
}

TEST(fahrenheit_to_celsion, c25_in_fahrenheit)
{
  EXPECT_EQ(77, celsius_to_fahrenheit(25));
}

TEST(fahrenheit_to_celsion, c90_in_fahrenheit)
{
  EXPECT_EQ(194, celsius_to_fahrenheit(90));
}

TEST(mm_to_dm, mm100_in_dm)
{
  EXPECT_EQ(1, mm_to_dm(100));
}

