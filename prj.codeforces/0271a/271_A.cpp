#include <iostream>
#include <array>

std::array<int, 4> year_to_digits(int year) {
    std::array<int, 4> result = {(year/1000), (year/100)%10, (year/10)%10, year%10};
    return  result;
}

bool is_digits_uniq(std::array<int, 4> digits) {
    bool is_uniq  = digits[0] != digits[1];
    is_uniq &= digits[0] != digits[2];
    is_uniq &= digits[0] != digits[3];
    is_uniq &= digits[1] != digits[2];
    is_uniq &= digits[1] != digits[3];
    is_uniq &= digits[2] != digits[3];
    return is_uniq;
}

int next_uniq_year(int year) {
    int next_year = year + 1;
    bool is_uniq = false;
    while(!is_uniq) {
        if (is_digits_uniq(year_to_digits(next_year))) {
            is_uniq = true;
        }
        else {
            ++next_year;
        }
    }
    return next_year;
}

int main() {
    int init_year = 0;
    std::cin >> init_year;
    std::cout << next_uniq_year(init_year) << std::endl;
    return 0;
}