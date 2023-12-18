#include <array>
#include <iostream>
int main() {
    const int n = 5;
    std::array<int, n> a{2, 4, 3, 1, 5};
    for(auto e: a) std::cout << e << ' ';
    return 0;
}