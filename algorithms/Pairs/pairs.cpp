#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int MAXX = 11;
const long long MOD = 1000000009;

bool vis[MAXN][MAXN][MAXX];
long long dp[MAXN][MAXN][MAXX];
vector<int> A, B;
int N, M, X;

long long solve(int pos_a, int pos_b, int taken) {
    if (taken == X) return 1;
    if (pos_a >= N) return 0;
    if (pos_b >= M) return 0;

    if (vis[pos_a][pos_b][taken]) return dp[pos_a][pos_b][taken] % MOD;

    vis[pos_a][pos_b][taken] = true;
    long long ans = 0;

    if (A[pos_a] > B[pos_b]) {
        ans = (ans + solve(pos_a + 1, pos_b + 1, taken + 1)) % MOD;
    }

    ans = (ans + solve(pos_a + 1, pos_b, taken)) % MOD;

    ans = (ans + solve(pos_a, pos_b + 1, taken)) % MOD;

    ans = (ans - solve(pos_a + 1, pos_b + 1, taken)) % MOD;

    return dp[pos_a][pos_b][taken] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> X;
    
    A.resize(N);
    B.resize(M);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            for(int k = 0; k < MAXX; k++) {
                dp[i][j][k] = 0;
                vis[i][j][k] = false;
            }
        }
    }
    
    long long res = solve(0, 0, 0) % MOD;
    
    cout << res << endl;
    return 0;
}

