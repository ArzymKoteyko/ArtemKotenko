#include <iostream>
#include <numeric>
#include <exception>
#include "rational.h"


Rational::Rational() {}

Rational::Rational(int num, int denum) {
    if (denum != 0) {
        if (denum < 0) {
            num *= -1;
            denum *= -1;
        }
        numenator = num;
        denumenator = denum;
        normalise();
    }
    else {
        throw std::invalid_argument("Can not create Rational with null denumenator");
    }
}

void Rational::normalise() {
    int gcd = std::gcd(numenator, denumenator);
    numenator /= gcd;
    denumenator /= gcd;
}

Rational& Rational::operator=(const Rational& oper) {
    numenator = oper.numenator;
    denumenator = oper.denumenator;
    normalise();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rational& oper) {
    os << oper.numenator << "/" << oper.denumenator;
    return os;
}

Rational operator-(const Rational& oper) {
    Rational res(oper.numenator * -1, oper.denumenator);
    return res;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int lcm = std::lcm(lhs.denumenator, rhs.denumenator);
    int lhsr = lcm / lhs.denumenator;
    int rhsr = lcm / rhs.denumenator;
    Rational res(lhs.numenator * lhsr + rhs.numenator * rhsr, lcm);
    return res;
}