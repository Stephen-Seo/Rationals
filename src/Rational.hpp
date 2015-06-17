
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <string>
#include <vector>
#include <mutex>

class Rational
{
public:
    Rational();
    Rational(long value);
    Rational(long numerator, long denominator);
    Rational(unsigned long numerator, unsigned long denominator, bool negative);

    Rational operator+ (const Rational& other) const;
    Rational operator- (const Rational& other) const;
    Rational operator* (const Rational& other) const;
    Rational operator/ (const Rational& other) const;

    int toInteger() const;
    long toLong() const;
    float toFloat() const;
    double toDouble() const;
    std::string toString() const;

    unsigned long getNumerator() const;
    unsigned long getDenominator() const;
    bool isNegative() const;
    bool isInvalid() const;
private:
    bool negative;
    unsigned long numerator;
    unsigned long denominator;

    void checkMultiples();

};

#endif

