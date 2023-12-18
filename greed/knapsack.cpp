#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
constexpr int W = 100;
struct Goods {
    int i, w, v;
    Goods(int w, int v): w(w), v(v), i(0) {}
    bool operator<(const Goods& g) const {
        return (double)v / w > (double)g.v / g.w;
    }
};
void greedly(std::vector<Goods>& v) {
    int cw = 0, i = 0;
    std::vector<double> t(v.size(), 0);
    double cv = 0, d;
    for(; i < v.size() && cw + v[i].w < W; ++i) {
        cv += v[i].v;
        cw += v[i].w;
        t[v[i].i] = 1;
    }
    if(i < v.size()) {
        d = double(W - cw) / v[i].w;
        t[v[i].i] = d;
        cv += d * v[i].v;
    }
    std::cout << "best value: " << cv << '\t';
    for(auto e: t)
        std::cout << e << ' ';
}
int main() {
    std::vector<Goods> v{Goods(10, 20), Goods(20, 30), Goods(30, 66), Goods(40, 40), Goods(50, 60)};
    for(int i = 0; i < v.size(); ++i) {
        v[i].i = i;
    }
    std::sort(v.begin(), v.end());
    greedly(v);
    return 0;
}