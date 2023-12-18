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
};

void bound(QNode& qN) { // 基于sort
    double tv = qN.cv;
    int tw = qN.cw;
    int i = qN.i + 2;
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
    std::queue<QNode> q;
    QNode e, e1, e2;
    e.i = -1, e.cw = 0, e.cv = 0;
    e.x.reserve(g.size());
    q.push(e);
    while(!q.empty()) {
        if(q.front().i == g.size() - 1) {
            if(q.front().cv > bestV) {
                bestX = q.front().x;
                bestV = q.front().cv;
            }
            q.pop();
            continue;
        }
        if(q.front().cw + g[q.front().i + 1].w <= W) {
            e1.i = q.front().i + 1, e1.cw = q.front().cw + g[q.front().i + 1].w, e1.cv = q.front().cv + g[q.front().i + 1].v;
            e1.x = q.front().x;
            e1.x.push_back(g[e1.i].no);
            q.push(e1);
        }
        bound(q.front());
        if(q.front().ub > bestV) {
            e2.i = q.front().i + 1, e2.cw = q.front().cw, e2.cv = q.front().cv;
            e2.x = q.front().x;
            q.push(e2);
        }
        q.pop();
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