#pragma once
#ifndef RATIONAL_RATIONAL_H_20220309
#define RATIONAL_RATIONAL_H_20220309


class Rational {

    private:
        void normalise();

    public:
        int numenator;
        int denumenator;
        Rational();
        Rational(int, int);
        Rational& operator=(const Rational&);
        
};

std::ostream& operator<<(std::ostream&, const Rational&);
Rational operator-(const Rational&);
Rational operator+(const Rational&, const Rational&);


#endif
