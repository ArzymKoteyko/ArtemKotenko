#include <iostream>

int main() {
    int dist = 0;
    int step = 0;
    std::cin >> dist;
    step += dist/5;
    if (dist%5!=0) {
        step++;
    }
    std::cout << step;
}