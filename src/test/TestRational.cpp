
#include "gtest/gtest.h"

#include "../Rational.hpp"

TEST(RationalTest, Addition)
{
    Rational a(1, 4);

    ASSERT_EQ(1.0/2.0, (a + Rational(1, 4)).toDouble());
    ASSERT_EQ(3.0/4.0, (a + Rational(2, 4)).toDouble());
    a = a + Rational(2, 5);

    ASSERT_EQ("13/20", a.toString());

    a = a + Rational(1, 10);

    ASSERT_EQ("3/4", a.toString());
}

TEST(RationalTest, Subtraction)
{
    Rational a(3, 4);

    ASSERT_EQ("1/2", (a - Rational(1, 4)).toString());
    ASSERT_EQ("1/4", (a - Rational(2, 4)).toString());
    ASSERT_EQ("0/1", (a - Rational(3, 4)).toString());
    ASSERT_EQ("-1/4", (a - Rational(1)).toString());
}

TEST(RationalTest, AdditionAndSubtraction)
{
    Rational a(3, 7);

    ASSERT_EQ("1/7", (a + Rational(2, 7, true)).toString());
    ASSERT_EQ("-1/7", (a + Rational(4, 7, true)).toString());

    a = Rational(3, 7, true);

    ASSERT_EQ("-5/7", (a - Rational(2, 7)).toString());
    ASSERT_EQ("-5/7", (a + Rational(2, 7, true)).toString());
    ASSERT_EQ("-1/1", (a - Rational(4, 7)).toString());
}

TEST(RationalTest, Multiplication)
{
    Rational a(2, 5);

    ASSERT_EQ("2/5", (a * Rational(2, 2)).toString());
    ASSERT_EQ("3/10", (a * Rational(3, 4)).toString());
    ASSERT_EQ("-12/35", (a * Rational(6, 7, true)).toString());
}

TEST(RationalTest, Division)
{
    Rational a(3, 5);

    ASSERT_EQ("3/5", (a / Rational(3, 3)).toString());
    ASSERT_EQ("3/10", (a / Rational(2, 1)).toString());
    ASSERT_EQ("-12/35", (a / Rational(7, 4, true)).toString());
}

TEST(RationalTest, PlusEquals)
{
    Rational a(3, 5);

    a += Rational(1, 5);
    ASSERT_EQ("4/5", a.toString());

    a += Rational(-2, 5);
    ASSERT_EQ("2/5", a.toString());
}

TEST(RationalTest, MinusEquals)
{
    Rational a(3, 5);

    a -= Rational(1, 5);
    ASSERT_EQ("2/5", a.toString());

    a -= Rational(2, -5);
    ASSERT_EQ("4/5", a.toString());
}

TEST(RationalTest, TimesEquals)
{
    Rational a(3, 5);

    a *= Rational(2, 3);
    ASSERT_EQ("2/5", a.toString());

    a *= Rational(-4, 7);
    ASSERT_EQ("-8/35", a.toString());
}

TEST(RationalTest, DivideEquals)
{
    Rational a(3, 5);

    a /= Rational(3, 2);
    ASSERT_EQ("2/5", a.toString());

    a /= Rational(7, -4);
    ASSERT_EQ("-8/35", a.toString());
}

TEST(RationalTest, EqualsNumber)
{
    Rational a(3, 5);

    a = 21;
    ASSERT_EQ("21/1", a.toString());
}

TEST(RationalTest, PlusNumber)
{
    Rational a(3, 5);

    a = a + 21;
    ASSERT_EQ("108/5", a.toString());
}

TEST(RationalTest, MinusNumber)
{
    Rational a(3, 5);

    a = a - 21;
    ASSERT_EQ("-102/5", a.toString());
}

TEST(RationalTest, TimesNumber)
{
    Rational a(3, 5);

    a = a * 21;
    ASSERT_EQ("63/5", a.toString());
}

TEST(RationalTest, DivideNumber)
{
    Rational a(3, 5);

    a = a / 21;
    ASSERT_EQ("1/35", a.toString());
}

TEST(RationalTest, PlusEqualsNumber)
{
    Rational a(3, 5);

    a += 21;
    ASSERT_EQ("108/5", a.toString());
}

TEST(RationalTest, MinusEqualsNumber)
{
    Rational a(3, 5);

    a -= 21;
    ASSERT_EQ("-102/5", a.toString());
}

TEST(RationalTest, TimesEqualsNumber)
{
    Rational a(3, 5);

    a *= 21;
    ASSERT_EQ("63/5", a.toString());
}

TEST(RationalTest, DivideEqualsNumber)
{
    Rational a(3, 5);

    a /= 21;
    ASSERT_EQ("1/35", a.toString());
}

