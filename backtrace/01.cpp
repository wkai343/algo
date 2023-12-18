#include <algorithm>
#include <vector>
#include <iostream>
struct Goods {
    int no, w, v;
    Goods(int no, int w, int v): no(no), w(w), v(v) {}
    bool operator<(const Goods& g) const {
        return (double)v / w > (double)g.v / g.w;
    }
};
std::vector<Goods> g{Goods(0, 5, 4), Goods(1, 3, 4), Goods(2, 2, 3), Goods(3, 1, 1)};
constexpr int W = 6;
std::vector<int> x; // cur
int cw, cv; // cur
std::vector<int> bestX; // bst
int bestV; // bst

double bound(int i) { // 基于sort
    double tv = cv;
    int tw = cw;
    while(i < g.size() && g[i].w + tw < W) {
        tw += g[i].w;
        tv += g[i].v;
        ++i;
    }
    if(i < g.size()) {
        tv += double(W - tw) / g[i].w * g[i].v;
    }
    return tv;
}
void dfs(int i = 0) {
    if(i == g.size()) {
        if(cv > bestV) {
            bestV = cv;
            bestX = x;
        }
    } else {
        if(cw + g[i].w <= W) {
            x.push_back(g[i].no);
            cw += g[i].w;
            cv += g[i].v;
            dfs(i + 1);
            x.pop_back();
            cw -= g[i].w;
            cv -= g[i].v;
        }
        if(bound(i + 1) > bestV)
            dfs(i + 1);
    }
}
int main() {
    x.reserve(g.size()), bestX.reserve(g.size());
    std::sort(g.begin(), g.end());
    dfs();
    std::cout << "best value: " << bestV << ", goods: ";
    for(auto e: bestX)
        std::cout << e << ' ';
    return 0;
}