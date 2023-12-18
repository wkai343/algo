#include <vector>
#include <iostream>
std::vector<bool> v;
void disp() {
    std::cout << "{ ";
    std::vector<bool>::iterator it;
    for(it = v.begin(); it != v.end(); ++it)
        if(*it) std::cout << it - v.begin() + 1 << ",";
    std::cout << "\b }  ";
}
void dfs(int i = 0) {
    if(i == v.size())
        disp();
    else {
        v[i] = true;
        dfs(i + 1);
        v[i] = false;
        dfs(i + 1);
    }
}
int main() {
    int n;
    std::cin >> n;
    v.resize(n);
    dfs();
}
