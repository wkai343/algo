#include <algorithm>
#include <vector>
#include <iostream>
struct Action {
    int beg, ed;
    Action(int b, int e): beg(b), ed(e) {}
    bool operator<(const Action& a) const {
        return ed < a.ed;
    }
};
void greedly(std::vector<Action>& v) {
    int preend = 0;
    std::vector<int> t;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i].beg >= preend) {
            t.push_back(i);
            preend = v[i].ed;
        }
    }
    for(int e: t)
        std::cout << e << ' ';
}
int main() {
    std::vector<Action> v{Action(1,4), Action(3, 5), Action(0, 6), Action(5, 7), Action(3, 8), \
    Action(5, 9), Action(6, 10), Action(8, 11), Action(8, 12), Action(2, 13), Action(12, 14)};
    std::sort(v.begin(), v.end());
    greedly(v);
    return 0;
}