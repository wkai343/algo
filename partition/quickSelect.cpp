#include <vector>
#include <iostream>
int partition(std::vector<int>& data, int left, int right) {
    int l = left, r = right;
    int base = data[left];
    while(l < r) {
        while(data[r] > base && l < r) --r;
        if(l < r) data[l++] = data[r];
        while(data[l] <= base && l < r) ++l;
        if(l < r) data[r--] = data[l];
        data[l] = base;
    }
    return l;
}
void quickSelect(std::vector<int>& data, int left, int right, int k) {
    if(left >= right) {
        if(left == k) {
            std::cout << data[left] << std::endl;
        }
    } else {
        int i = partition(data, left, right);
        if(i == k) {
            std::cout << data[i] << std::endl;
        } else if(k < i) {
            quickSelect(data, left, i - 1, k);
        } else {
            quickSelect(data, i + 1, right, k);
        }
    }
}
int main() {
    std::vector<int> v{2, 5, 1, 4, 3};
    quickSelect(v, 0, v.size() - 1, 2);
    return 0;
}