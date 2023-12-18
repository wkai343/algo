#include <vector>
#include <iostream>
std::vector<int> v;
bool place(int i, int j) {
    if(i == 0) return true;
    for(int k = 0; k < i; ++k) {
        if(v[k] == j || abs(v[k] - j) == abs(k - i))
            return false;
    }
    return true;
}
void disp() {
    for(int i = 0; i < v.size(); ++i) {
        std::cout << '(' << i << ", " << v[i] << ") ";
    }
    std::cout << std::endl;
}
void dfs(int i = 0) {
    if(i == v.size()) {
        disp();
        return;
    }
    for(int j = 0; j < v.size(); ++j) {
        if(place(i, j)) {
            v[i] = j;
            dfs(i + 1);
            v[i] = 0;
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    v.resize(n);
    dfs();
    return 0;
}