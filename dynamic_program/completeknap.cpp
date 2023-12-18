#include <cstring>
#include <iostream>
constexpr int n = 3, W = 7;
int w[n]{3, 4, 2}, v[n]{4, 5, 3}, x[n];
int dp[n + 1][W + 1], fk[n + 1][W + 1], dp1[W + 1], k[n];
int knap() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= W; ++j)
            for(int k = 0; k * w[i - 1] <= j; ++k) 
                if(dp[i - 1][j - k * w[i - 1]] + k * v[i - 1] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - k * w[i - 1]] + k * v[i - 1];
                    fk[i][j] = k;
                }
    return dp[n][W];
}
int knap1() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= W; ++j) 
            if(w[i - 1] > j) 
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - w[i - 1]] + v[i - 1]);
    return dp[n][W];
}
int knap2() {
    for(int i = 1; i <= n; ++i)
        for(int j = w[i - 1]; j <= W; ++j)
            dp1[j] = std::max(dp1[j], dp1[j - w[i - 1]] + v[i - 1]); 
    return dp1[W];
}
// void getX() {
//     int j = W;
//     for(int i = n; i > 0; --i) {
//         if(dp[i][j] == dp[i - 1][j]) {
//             x[i - 1] = 0;
//         } else {
//             x[i - 1] = fk[i][j];
//             j -= x[i - 1] * w[i - 1];
//         }
//     }
// }
void getX() {
    int j = W;
    for(int i = n; i > 0; --i) {
        x[i - 1] = fk[i][j];
        j -= x[i - 1] * w[i - 1];
    }
}
int main() {
    std::cout << knap() << std::endl;
    getX();
    for(auto e: x)
        std::cout << e << ' ';
    return 0;
}