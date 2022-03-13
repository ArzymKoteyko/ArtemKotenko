#include <iostream>
#include <numeric>
#include <algorithm>
#include <exception>
#include "rational.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

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
    int rgcd = gcd(numenator, denumenator);
    numenator /= rgcd;
    denumenator /= rgcd;
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
    int rlcm = lcm(lhs.denumenator, rhs.denumenator);
    int lhsr = rlcm / lhs.denumenator;
    int rhsr = rlcm / rhs.denumenator;
    Rational res(lhs.numenator * lhsr + rhs.numenator * rhsr, rlcm);
    return res;
}