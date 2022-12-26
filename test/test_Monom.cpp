#include "gtest.h"
#include "Monom.h"

TEST(TMonom, can_create_monom)
{
  ASSERT_NO_THROW(TMonom a(3));
}

TEST(TMonom, cant_create_monom_with_negative_length)
{
  ASSERT_ANY_THROW(TMonom a(-1));
}

TEST(TMonom, can_setK)
{
  TMonom a(3);

  ASSERT_NO_THROW(a.SetK(5.0));
}