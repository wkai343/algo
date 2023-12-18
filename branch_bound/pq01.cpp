#include <algorithm>
#include <queue>
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
std::vector<int> bestX;
int bestV;
struct QNode {
    int i, cw, cv;
    double ub;
    std::vector<int> x;
    bool operator<(const QNode& qN) const {
        return ub < qN.ub;
    }
};

void bound(QNode& qN) { // 基于sort
    double tv = qN.cv;
    int tw = qN.cw;
    int i = qN.i + 1;
    while(i < g.size() && g[i].w + tw < W) {
        tw += g[i].w;
        tv += g[i].v;
        ++i;
    }
    if(i < g.size()) {
        tv += double(W - tw) / g[i].w * g[i].v;
    }
    qN.ub = tv;
}
void bfs() {
    std::priority_queue<QNode> q;
    QNode e, e1, e2;
    e.i = -1, e.cw = 0, e.cv = 0;
    e.ub = 0;
    e.x.reserve(g.size());
    q.push(e);
    while(!q.empty()) {
        e = q.top();
        q.pop();
        if(e.i == g.size() - 1) {
            if(e.cv > bestV) {
                bestX = e.x;
                bestV = e.cv;
            }
            q.pop();
            continue;
        }
        if(e.cw + g[e.i + 1].w <= W) {
            e1.i = e.i + 1, e1.cw = e.cw + g[e.i + 1].w, e1.cv = e.cv + g[e.i + 1].v;
            e1.x = e.x;
            e1.x.push_back(g[e1.i].no);
            bound(e1);
            q.push(e1);
        }
        e2.i = e.i + 1, e2.cw = e.cw, e2.cv = e.cv;
        e2.x = e.x;
        bound(e2);
        if(e2.ub > bestV) {
            q.push(e2);
        }
    }
}
int main() {
    std::sort(g.begin(), g.end());
    bfs();
    std::cout << "best value: " << bestV << ", goods: ";
    for(auto e: bestX)
        std::cout << e << ' ';
    return 0;
}