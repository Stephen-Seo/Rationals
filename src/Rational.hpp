
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <string>
#include <vector>
#include <mutex>

class Rational
{
public:
    Rational();
    Rational(long long value);
    Rational(long long numerator, long long denominator);
    Rational(unsigned long long numerator, unsigned long long denominator, bool negative);
    Rational(const Rational& other);

    Rational operator= (const Rational& other);
    Rational operator+ (const Rational& other) const;
    Rational operator- (const Rational& other) const;
    Rational operator* (const Rational& other) const;
    Rational operator/ (const Rational& other) const;

    Rational operator+= (const Rational& other);
    Rational operator-= (const Rational& other);
    Rational operator*= (const Rational& other);
    Rational operator/= (const Rational& other);

    bool operator== (const Rational& other) const;
    bool operator< (const Rational& other) const;
    bool operator> (const Rational& other) const;
    bool operator<= (const Rational& other) const;
    bool operator>= (const Rational& other) const;

    int toInteger() const;
    long toLong() const;
    long long toLLong() const;
    float toFloat() const;
    double toDouble() const;
    std::string toString() const;

    unsigned long long getNumerator() const;
    unsigned long long getDenominator() const;
    bool isNegative() const;
    bool isInvalid() const;
private:
    bool negative;
    unsigned long long numerator;
    unsigned long long denominator;

    void checkMultiples();

};

#endif

