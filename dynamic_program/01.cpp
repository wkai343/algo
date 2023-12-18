#include <cstring>
#include <iostream>
constexpr int n = 5, W = 10;
int w[]{2, 2, 6, 5, 4}, v[]{6, 3, 5, 4, 6}, dp[n + 1][W + 1], x[n], dp1[W + 1];
int knap() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= W; ++j)
            if(w[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
    return dp[n][W];
}
int knap1() {
    for(int i = 1; i <= n; ++i)
        for(int j = W; j >= 0; --j)
            if(w[i - 1] > j) {
                dp1[j] = dp1[j];
            } else {
                dp1[j] = std::max(dp1[j], dp1[j - w[i - 1]] + v[i - 1]);
            }
    return dp1[W];
}
int knap2() {
    for(int i = 1; i <= n; ++i)
        for(int j = W; j >= w[i - 1]; --j)
            dp1[j] = std::max(dp1[j], dp1[j - w[i - 1]] + v[i - 1]);
    return dp1[W];
}
void getX() {
    int j = W;
    for(int i = n; i > 0; --i)
        if(dp[i][j] == dp[i - 1][j]) {
            x[i - 1] = 0;
        } else {
            x[i - 1] = 1;
            j -= w[i - 1];
        }
}
int main() {
    std::cout << knap() << std::endl;
    getX();
    for(auto e: x)
        std::cout << e << ' ';
    // std::cout << knap2() << std::endl;
    return 0;
}