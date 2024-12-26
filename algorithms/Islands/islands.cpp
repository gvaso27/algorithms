#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<long long> subMax, outPath, startMax;
    vector<int> iter, fin, dfsStk, pathDist, par;
    vector<char> vis, onCycle;
    int cStart, cEnd, cLen, stkSize, n;

public:
    Solution(int size) : n(size) {
        adj.resize(size);
        subMax.resize(size);
        outPath.resize(size);
        startMax.resize(size);
        iter.resize(size);
        fin.resize(size);
        dfsStk.resize(size);
        pathDist.resize(size);
        par.resize(size);
        vis.resize(size);
        onCycle.resize(size);
    }

    void addEdge(int u, int v, int w) {
        adj[v].emplace_back(u, w);
        adj[u].emplace_back(v, w);
    }

    long long solve() {
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res += computeTree(i);
            }
        }
        return res;
    }

private:

    void dfs(int src) {
        stkSize = 0;
        dfsStk[stkSize++] = src;

        while (stkSize > 0) {
            int cur = dfsStk[stkSize - 1];
            if (!vis[cur]) {
                vis[cur] = 1;
                iter[cur] = -1;
            }
            
            bool processed = false;
            for (iter[cur]++; iter[cur] < (int)adj[cur].size(); iter[cur]++) {
                int nbr = adj[cur][iter[cur]].first;

                if (nbr == par[cur] && !fin[cur]) {
                    fin[cur] = 1;
                    adj[cur][iter[cur]].first = -1;
                    processed = true;
                    break;
                }
                
                if (vis[nbr]) {
                    if (vis[nbr] == 2) {
                        adj[cur][iter[cur]].first = -1;
                        processed = true;
                        break;
                    }

                    cStart = cur;
                    cEnd = nbr;
                    cLen = adj[cur][iter[cur]].second;
                    onCycle[cur] = 1;
                    adj[cur][iter[cur]].first = -1;
                    processed = true;
                    break;
                }

                par[nbr] = cur;
                pathDist[nbr] = adj[cur][iter[cur]].second;
                dfsStk[stkSize++] = nbr;
                processed = true;
                break;
            }

            if (processed) continue;
            
            vis[cur]++;
            long long secMax = 0;
            
            for (const auto& [nbr, dist] : adj[cur]) {
                if (nbr < 0) continue;
                
                onCycle[cur] |= onCycle[nbr];
                subMax[cur] = max(subMax[cur], subMax[nbr]);
                
                if (startMax[nbr] + dist > startMax[cur]) {
                    secMax = startMax[cur];
                    startMax[cur] = startMax[nbr] + dist;
                } else {
                    secMax = max(secMax, startMax[nbr] + dist);
                }

                if (!onCycle[nbr]) {
                    outPath[cur] = max(outPath[cur], startMax[nbr] + dist);
                }
            }

            subMax[cur] = max(subMax[cur], startMax[cur] + secMax);
            stkSize--;
        }
    }


    long long computeCycle() {
        int node;
        long long pLen = 0, append = 0, total = 0, tmp = 0;
        
        node = cStart;
        while (node != cEnd) {
            append = max(append, pLen + outPath[node]);
            pLen += pathDist[node];
            node = par[node];
        }
        tmp = cLen + append;
        node = cEnd;
        pLen = append = 0;
        while (node >= 0) {
            append = max(append, pLen + outPath[node]);
            pLen += pathDist[node];
            node = par[node];
        }
        total = max(total, tmp + append);
        
        pLen = 0;
        node = cStart;
        while (node != cEnd) {
            pLen += pathDist[node];
            node = par[node];
        }
        long long back = pLen;
        
        append = 0;
        node = par[cStart];
        pLen -= pathDist[cStart];
        while (node != cEnd) {
            append = max(append, outPath[node] + pLen);
            pLen -= pathDist[node];
            node = par[node];
        }
        total = max(total, append + cLen + startMax[cStart]);
        
        node = cStart;
        pLen = 0;
        while (node != cEnd) {
            pLen = max(pLen, outPath[node]);
            pLen -= pathDist[node];
            append = cLen + back + pLen + outPath[par[node]];
            total = max(total, append);
            node = par[node];
        }
        return total;
    }

    long long computeTree(int root) {
        pathDist[root] = 0;
        cStart = cEnd = par[root] = -1;
        cLen = 0;
        dfs(root);
        return max(computeCycle(), subMax[root]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    Solution sol(n);
    
    for (int i = 0; i < n; i++) {
        int u, w;
        cin >> u >> w;
        sol.addEdge(i, u-1, w);
    }
    
    cout << sol.solve() << endl;
    return 0;
}


