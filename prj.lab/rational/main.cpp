#include <iostream>
#include <exception>
#include "rational.h"

int main() {
    Rational r(1,-2);
    Rational a = r;
    Rational b = a + a;
    std::cout << "r: " << r << "\t-r: " << -r << std::endl;
    std::cout << r << " " << a << " " << b << " " << std::endl; 
    std::cout << "test completed" << std::endl;
    return 0;
}