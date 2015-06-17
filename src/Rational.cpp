
#include "Rational.hpp"

#include <cstdlib>

Rational::Rational() :
numerator(0),
denominator(1)
{}

Rational::Rational(long value) :
negative(value < 0),
numerator(std::abs(value)),
denominator(1)
{}

Rational::Rational(long numerator, long denominator) :
negative((numerator < 0 && denominator >= 0) || (numerator >= 0 && denominator < 0)),
numerator(std::abs(numerator)),
denominator(std::abs(denominator))
{
    checkMultiples();
}

Rational::Rational(unsigned long numerator, unsigned long denominator, bool negative) :
negative(negative),
numerator(numerator),
denominator(denominator)
{
    checkMultiples();
}

Rational Rational::operator+ (const Rational& other) const
{
    if(negative == other.negative)
    {
        if(denominator == other.denominator)
        {
            return Rational(numerator + other.numerator, denominator, negative);
        }
        else
        {
            return Rational(numerator * other.denominator + other.numerator * denominator,
                            denominator * other.denominator,
                            negative);
        }
    }
    else
    {
        if(negative)
        {
            return other - Rational(numerator, denominator, false);
        }
        else
        {
            return *this - Rational(other.numerator, other.denominator, false);
        }
    }
}

Rational Rational::operator- (const Rational& other) const
{
    if(negative != other.negative)
    {
        if(negative)
        {
            return *this + Rational(other.numerator, other.denominator, true);
        }
        else
        {
            return *this + Rational(other.numerator, other.denominator, false);
        }
    }
    else
    {
        if(denominator == other.denominator)
        {
            if(numerator >= other.numerator)
            {
                return Rational(numerator - other.numerator, denominator, negative);
            }
            else
            {
                return Rational(other.numerator - numerator, denominator, !negative);
            }
        }
        else
        {
            unsigned long a_n = numerator * other.denominator;
            unsigned long b_n = other.numerator * denominator;
            if(a_n >= b_n)
            {
                return Rational(a_n - b_n, denominator * other.denominator, negative);
            }
            else
            {
                return Rational(b_n - a_n, denominator * other.denominator, !negative);
            }
        }
    }
}

Rational Rational::operator* (const Rational& other) const
{
    return Rational(numerator * other.numerator, denominator * other.denominator, !(negative == other.negative));
}

Rational Rational::operator/ (const Rational& other) const
{
    return *this * Rational(other.denominator, other.numerator, other.negative);
}

int Rational::toInteger() const
{
    return (int) (numerator / denominator) * (negative ? -1 : 1);
}

long Rational::toLong() const
{
    return (long) (numerator / denominator) * (negative ? -1L : 1L);
}

float Rational::toFloat() const
{
    return (float) numerator / (float) denominator * (negative ? -1.0f : 1.0f);
}

double Rational::toDouble() const
{
    return (double) numerator / (double) denominator * (negative ? -1.0 : 1.0);
}

std::string Rational::toString() const
{
    if(negative)
    {
        return std::string("-") + std::to_string(numerator) + std::string("/") + std::to_string(denominator);
    }
    else
    {
        return std::to_string(numerator) + std::string("/") + std::to_string(denominator);
    }
}

unsigned long Rational::getNumerator() const
{
    return numerator;
}

unsigned long Rational::getDenominator() const
{
    return denominator;
}

bool Rational::isNegative() const
{
    return negative;
}

bool Rational::isInvalid() const
{
    return denominator == 0L;
}

void Rational::checkMultiples()
{
    unsigned long min = numerator < denominator ? numerator : denominator;

    bool changed;
    while(true)
    {
        changed = false;
        for(int i = 2; i <= min; ++i)
        {
            if(numerator % i == 0 && denominator % i == 0)
            {
                changed = true;
                numerator /= i;
                denominator /= i;
                min = numerator < denominator ? numerator : denominator;
                break;
            }
        }
        if(!changed)
        {
            break;
        }
    }

    if(denominator == 0L)
    {
        numerator = 1L;
        negative = false;
    }
    else if(numerator == 0L)
    {
        denominator = 1L;
        negative = false;
    }
}

