#include <iostream>
#include <vector>
#include <algorithm>
void solve(std::vector<int>& v, int left, int right, int& max1, int& max2) {
    if(left == right)
        max1 = v[left], max2 = -0x3f3f3f3f;
    else if(left == right - 1)
        max1 = std::max(v[left], v[right]), max2 = std::min(v[left], v[right]);
    else {
        int lMax1, lMax2, rMax1, rMax2, mid = (left + right) >> 1;
        solve(v, left, mid, lMax1, lMax2);
        solve(v, mid + 1, right, rMax1, rMax2);
        if(lMax1 < rMax2) {
            std::swap(lMax1, rMax1);
            std::swap(lMax2, rMax2);
        }
        max1 = lMax1, max2 = std::max(lMax2, rMax1);
    }
}
int main() {
    std::vector<int> v{2, 4, 3, 1, 2};
    int max1, max2;
    solve(v, 0, v.size(), max1, max2);
    std::cout << max1 << ' ' << max2 << std::endl;
    return 0;
}