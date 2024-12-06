#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> dp;
vector<int> P;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    dp.resize(N + 1, INT_MAX);
    
    dp[0] = 0;

    P.resize(N);

    for (int& p : P) {
        cin >> p;
    }
    
    int distinctDishes = 0;
    int dish;

    for (int i = 1; i <= N; ++i) {
        distinctDishes = 0;
        
        unordered_map<int, int> freq;
        
        for (int j = i; j > 0; --j) {
            dish = P[j - 1];
            if (freq[dish]++ == 0) {
                ++distinctDishes;
            }
            dp[i] = min(dp[i], distinctDishes * distinctDishes + dp[j - 1]);
        }
    }
    
    cout << dp[N] << endl;

    return 0;
}
