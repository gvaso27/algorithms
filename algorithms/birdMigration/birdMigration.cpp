#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int maxFree = 0;
    int prefixFree = 0;
    int suffixFree = 0;
    int len = 0;
    bool needsUpdate = false;
    bool updateValue = false;
};

vector<Node> tree;
int N;

void applyUpdate(int v) {
    if (!tree[v].needsUpdate) return;
    
    if (tree[v].updateValue) { 
        tree[v].maxFree = tree[v].prefixFree = tree[v].suffixFree = 0;
    } else {
        tree[v].maxFree = tree[v].prefixFree = tree[v].suffixFree = tree[v].len;
    }
    
    if (v * 2 + 1 < tree.size()) {
        for (int i = 0; i < 2; i++) {
            tree[v * 2 + i].needsUpdate = true;
            tree[v * 2 + i].updateValue = tree[v].updateValue;
        }
    }
    tree[v].needsUpdate = false;
}

Node merge(const Node& left, const Node& right) {
    Node res;
    res.len = left.len + right.len;
    
    res.prefixFree = (left.prefixFree == left.len) ? left.prefixFree + right.prefixFree : left.prefixFree;
    res.suffixFree = (right.suffixFree == right.len) ? right.suffixFree + left.suffixFree : right.suffixFree;
    
    res.maxFree = max({left.maxFree, right.maxFree, left.suffixFree + right.prefixFree});
    return res;
}

void buildTree(int v, int tl, int tr) {
    tree[v].len = tr - tl + 1;
    if (tl == tr) {
        tree[v].maxFree = tree[v].prefixFree = tree[v].suffixFree = 1;
        return;
    }
    
    int tm = (tl + tr) / 2;
    buildTree(v * 2, tl, tm);
    buildTree(v * 2 + 1, tm + 1, tr);
    tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
}

void rangeUpdate(int v, int tl, int tr, int l, int r, bool val) {
    applyUpdate(v);
    if (l > tr || r < tl) return;
    
    if (l <= tl && tr <= r) {
        tree[v].needsUpdate = true;
        tree[v].updateValue = val;
        applyUpdate(v);
        return;
    }
    
    int tm = (tl + tr) / 2;
    rangeUpdate(v * 2, tl, tm, l, r, val);
    rangeUpdate(v * 2 + 1, tm + 1, tr, l, r, val);
    tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
}

pair<bool, int> findFirstFit(int v, int tl, int tr, int spaces) {
    applyUpdate(v);
    if (tree[v].maxFree < spaces) return {false, -1};
    if (tl == tr) return {true, tl};
    
    int tm = (tl + tr) / 2;
    applyUpdate(v * 2);
    applyUpdate(v * 2 + 1);
    
    if (tree[v * 2].maxFree >= spaces) {
        return findFirstFit(v * 2, tl, tm, spaces);
    }
    
    if (tree[v * 2].suffixFree + tree[v * 2 + 1].prefixFree >= spaces) {
        int leftPart = min(tree[v * 2].suffixFree, spaces);
        return {true, tm - leftPart + 1};
    }
    
    if (tree[v * 2 + 1].maxFree >= spaces) {
        return findFirstFit(v * 2 + 1, tm + 1, tr, spaces);
    }
    
    return {false, -1};
}

pair<bool, int> addBirds(int spaces) {
    if (spaces > N) return {false, -1};
    return findFirstFit(1, 0, N - 1, spaces);
}

void removeBirds(int start, int count) {
    if (start >= 0 && start + count <= N) {
        rangeUpdate(1, 0, N - 1, start, start + count - 1, false);
    }
}

void occupySpace(int start, int count) {
    if (start >= 0 && start + count <= N) {
        rangeUpdate(1, 0, N - 1, start, start + count - 1, true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M;
    cin >> N >> M;
    
    tree.resize(4 * N);
    buildTree(1, 0, N - 1);
    
    while (M--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int p;
            cin >> p;
            auto [found, pos] = addBirds(p);
            if (found) {
                occupySpace(pos, p);
                cout << pos + 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            int a, b;
            cin >> a >> b;
            removeBirds(a - 1, b);
        }
    }
    
    return 0;
}
