#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef INPUT_FILE
    freopen("INPUT_FILE.txt", "r", stdin);
    #endif
    int numSegments, removalLimit;
    cin >> numSegments >> removalLimit;
    vector<pair<int, int>> segments;
    for(int i = 0; i < numSegments; i++) {
        int start, end;
        cin >> start >> end;
        segments.emplace_back(start, end);
    }
    sort(all(segments));
    vector<pair<int, int>> selectedSegments(1);
    int maxRight = 0;
    for(int i = 0; i < numSegments; i++) {
        if(segments[i].second < maxRight) {
            removalLimit--;
            continue;
        }
        selectedSegments.push_back(segments[i]);
        maxRight = segments[i].second;
    }
    numSegments = sz(selectedSegments) - 1;
    removalLimit = max(removalLimit, 0);
    vector<vector<int>> dp(numSegments + 1, vector<int>(removalLimit + 1, 0));
    dp[1][0] = selectedSegments[1].second - selectedSegments[1].first;
    for(int i = 2; i <= numSegments; i++) {
        dp[i][0] = dp[i - 1][0] + selectedSegments[i].second - max(selectedSegments[i].first, selectedSegments[i - 1].second);
    }
    if(removalLimit == 0) {
        cout << dp[numSegments][0] << endl;
        return 0;
    }
    deque<pair<int, int>> dpMaxRight[numSegments + 1];
    int firstOut = 0;
    for(int i = 1; i <= numSegments; i++) {
        while(selectedSegments[firstOut + 1].second < selectedSegments[i].first) {
            firstOut++;
        }
        for(int j = 0; j <= min(removalLimit, i); j++) {
            int di = i - j;
            if(j) {
                if(i == j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                    while(sz(dpMaxRight[di - 1]) && dpMaxRight[di - 1].front().second <= firstOut) {
                        dpMaxRight[di - 1].pop_front();
                    }
                    if(sz(dpMaxRight[di - 1])) {
                        dp[i][j] = max(dp[i][j], dpMaxRight[di - 1].front().first + selectedSegments[i].second);
                    }
                    if(j >= i - firstOut - 1) {
                        dp[i][j] = max(dp[i][j], dp[firstOut][j - (i - firstOut - 1)] + selectedSegments[i].second - selectedSegments[i].first);
                    }
                }
            }
            int val = dp[i][j] - selectedSegments[i].second;
            while(sz(dpMaxRight[di]) && dpMaxRight[di].back().first < val) {
                dpMaxRight[di].pop_back();
            }
            dpMaxRight[di].push_back({val, i});
           
        }
    }
    cout << dp[numSegments][removalLimit] << endl;
    return 0;
}
