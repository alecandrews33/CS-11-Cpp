#include "rational.h"

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator of 0 error");
    }
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    this->numerator = numerator;
    this->denominator = denominator;
}

int Rational::num() const {
    return this->numerator;
}

int Rational::denom() const {
    return this->denominator;
}

Rational Rational::reciprocal() const {
    return Rational(this->denominator, this->numerator);
}

int Rational::gcd(int a, int b) const {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void Rational::reduce() {
    int divisor = gcd(this->numerator, this->denominator);
    this->numerator /= divisor;
    this->denominator /= divisor;
}

Rational & Rational::operator+=(const Rational &rhs) {
    if (this != &rhs) {
      numerator *= rhs.denom();
      numerator += (rhs.num() * denominator);
      denominator *= rhs.denom();
      (*this).reduce();
      return *this;
    }
    return (*this *= 2);

}

Rational & Rational::operator-=(const Rational &rhs) {
    if (this != &rhs) {
        Rational flip = Rational((-1) * rhs.num(), (-1) * -rhs.denom());
        return *this += flip;
    }
    numerator = 0;
    denominator = 1;
    return *this;
}

Rational & Rational::operator*=(const Rational &rhs) {
    numerator *= rhs.num();
    denominator *= rhs.denom();
    this->reduce();
    return *this;
}

Rational & Rational::operator/=(const Rational &rhs) {
    Rational flip = rhs.reciprocal();
    return *this *= flip;
}

Rational operator+(const Rational &x, const Rational &y) {
    Rational result = x;
    result += y;
    return result;
}

Rational operator-(const Rational &x, const Rational &y) {
    Rational result = x;
    result -= y;
    return result;
}

// Non-member operator overload of *
Rational operator*(const Rational &x, const Rational &y) {
    Rational result = x;
    result *= y;
    return result;
}

Rational operator/(const Rational &x, const Rational &y) {
    Rational flip = y.reciprocal();
    return x * flip;
}

ostream & operator<<(ostream &os, const Rational &r) {
    if (r.denom() == 1) {
        os << r.num();
    }
    else {
        os << r.num() << "/" << r.denom();
    }
    return os;
}
