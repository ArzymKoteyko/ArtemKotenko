#include <iostream>
#include <cmath>

int calc_fi(int fi, int ti, int k) {
    return std::min(fi, fi-(ti-k));
}
int find_max_fi(int n, int k) {
    int fi = 0;
    int ti = 0;
    std::cin >> fi >> ti;
    int fi_max = calc_fi(fi, ti, k);
    for (int i=0; i<n-1; i++) {
        std::cin >> fi >> ti;
        fi_max = std::max(fi_max, calc_fi(fi, ti, k));
    }
    return fi_max;
}

int main() {
    long n = 0;
    long k = 0;
    std::cin >> n >> k;
    std::cout << find_max_fi(n, k) << std::endl;
    return 0;
}