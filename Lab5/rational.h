#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <set>

using namespace std;

/**
 * A class to represent rational numbers as numerators and denominators
 */
class Rational {
    /** Integer representing numerator of number */
    int numerator;
    /** Integer representing denominator of number */
    int denominator;

    /**
     * Function that finds the greatest common divisor between a and y
     *
     * @param a First value to get divisor of
     * @param b Second value to get divisor of
     * @return The greatest common divisor
     */
    int gcd(int a, int b) const;

public:
    /**
     * Two argument constructor that takes in a numerator and denominator.
     * Default value of 0 for numerator and 1 for denominator. If the denominator
     * is 0, throw invalid argument error. Negate numerator and denominator if
     * denominator is negative.
     *
     * @param numerator Defaults to 0 and is numerator of rational num
     * @param denominator Defaults to 1 and is denominator of rational num
     * @return The Rational object being initialized
     */
    Rational(int numerator = 0, int denominator = 1);

    /**
     * Accessors for the numerator of the rational number
     *
     * @return The numerator
     */
    int num() const;

    /**
     * Accessors for the denominator of the rational number
     *
     * @return The denominator
     */
    int denom() const;

    /**
     * Method that returns the reciprocal of a rational number
     *
     * @return The reciprocal of this Rational number
     */
    Rational reciprocal() const;

    /** Member function to fully reduce a rational number */
    void reduce();

    /** Member operator overload of += */
    Rational & operator+=(const Rational &rhs);

    /** Member operator overload of -= */
    Rational & operator-=(const Rational &rhs);

    /** Member operator overload of *= */
    Rational & operator*=(const Rational &rhs);

    /** Member operator overload of /= */
    Rational & operator/=(const Rational &rhs);

};

/** Non-member operator overload of + */
Rational operator+(const Rational &x, const Rational &y);

/** Non-member operator overload of - */
Rational operator-(const Rational &x, const Rational &y);

/** Non-member operator overload of * */
Rational operator*(const Rational &x, const Rational &y);

/** Non-member operator overload of / */
Rational operator/(const Rational &x, const Rational &y);

/** Non-member stream-output operator */
ostream & operator<<(ostream &os, const Rational &r);
