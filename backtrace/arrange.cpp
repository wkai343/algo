#include <vector>
#include <iostream>
std::vector<int> v;
void disp() {
    std::cout << "{ ";
    for(auto e: v)
        std::cout << e << ',';
    std::cout << "\b }  ";
}
void dfs(int i = 0) {
    if(i == v.size())
        disp();
    else {
        dfs(i + 1);
        for(int j = i + 1; j < v.size(); ++j) {
            std::swap(v[i], v[j]);
            dfs(i + 1);
            std::swap(v[i], v[j]);
        }
    }
}
int main() {
    int n;
    std::cin >> n;
    v.reserve(n);
    for(int i = 0; i < n; ++i) {
        v.push_back(i + 1);
    }
    dfs();
    return 0;
}