
#include "Rational.hpp"

#include <cstdlib>
#include <cmath>

Rational::Rational() :
numerator(0ULL),
denominator(1ULL)
{}

Rational::Rational(long long value) :
negative(value < 0),
numerator(std::abs(value)),
denominator(1ULL)
{}

Rational::Rational(long long numerator, long long denominator) :
negative((numerator < 0 && denominator >= 0) || (numerator >= 0 && denominator < 0)),
numerator(std::abs(numerator)),
denominator(std::abs(denominator))
{
    checkMultiples();
}

Rational::Rational(unsigned long long numerator, unsigned long long denominator, bool negative) :
negative(negative),
numerator(numerator),
denominator(denominator)
{
    checkMultiples();
}

Rational::Rational(const Rational& other) :
negative(other.negative),
numerator(other.numerator),
denominator(other.denominator)
{
    checkMultiples();
}

Rational Rational::operator= (const Rational& other)
{
    negative = other.negative;
    numerator = other.numerator;
    denominator = other.denominator;

    return *this;
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
            unsigned long long a_n = numerator * other.denominator;
            unsigned long long b_n = other.numerator * denominator;
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

Rational Rational::operator+= (const Rational& other)
{
    *this = *this + other;

    return *this;
}

Rational Rational::operator-= (const Rational& other)
{
    *this = *this - other;

    return *this;
}

Rational Rational::operator*= (const Rational& other)
{
    *this = *this * other;

    return *this;
}

Rational Rational::operator/= (const Rational& other)
{
    *this = *this / other;

    return *this;
}

bool Rational::operator== (const Rational& other) const
{
    return negative == other.negative &&
           numerator == other.numerator &&
           denominator == other.denominator;
}

bool Rational::operator< (const Rational& other) const
{
    if(negative != other.negative)
    {
        return negative;
    }
    else if(denominator == other.denominator)
    {
        if(negative)
        {
            return numerator > other.numerator;
        }
        else
        {
            return numerator < other.numerator;
        }
    }
    else
    {
        unsigned long long a = numerator * other.denominator;
        unsigned long long b = other.numerator * denominator;

        if(negative)
        {
            return a > b;
        }
        else
        {
            return a < b;
        }
    }
}

bool Rational::operator> (const Rational& other) const
{
    return other < *this;
}

bool Rational::operator<= (const Rational& other) const
{
    if(*this == other)
    {
        return true;
    }
    else
    {
        return *this < other;
    }
}

bool Rational::operator>= (const Rational& other) const
{
    if(*this == other)
    {
        return true;
    }
    else
    {
        return other < *this;
    }
}

int Rational::toInteger() const
{
    return (int) (numerator / denominator) * (negative ? -1 : 1);
}

long Rational::toLong() const
{
    return (long) (numerator / denominator) * (negative ? -1L : 1L);
}

long long Rational::toLLong() const
{
    return (long long) (numerator / denominator) * (negative ? -1LL : 1LL);
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

unsigned long long Rational::getNumerator() const
{
    return numerator;
}

unsigned long long Rational::getDenominator() const
{
    return denominator;
}

bool Rational::isNegative() const
{
    return negative;
}

bool Rational::isInvalid() const
{
    return denominator == 0ULL;
}

void Rational::checkMultiples()
{
    unsigned long long min = numerator < denominator ? numerator : denominator;

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

    if(denominator == 0ULL)
    {
        numerator = 1ULL;
        negative = false;
    }
    else if(numerator == 0ULL)
    {
        denominator = 1ULL;
        negative = false;
    }
}

