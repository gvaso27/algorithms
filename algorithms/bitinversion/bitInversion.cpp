#include <iostream>
#include <vector>

using namespace std;

vector<int> tree, lazy;

void apply(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            lazy[node * 2 + 1] ^= lazy[node];
            lazy[node * 2 + 2] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int start, int end, int l, int r) {
    apply(node, start, end);

    if (start > end || start > r || end < l)
        return;

    if (start >= l && end <= r) {
        lazy[node] ^= 1;
        apply(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(node * 2 + 1, start, mid, l, r);
    updateRange(node * 2 + 2, mid + 1, end, l, r);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int queryRange(int node, int start, int end, int l, int r) {
    apply(node, start, end);

    if (start > end || start > r || end < l)
        return 0;

    if (start >= l && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int leftSum = queryRange(node * 2 + 1, start, mid, l, r);
    int rightSum = queryRange(node * 2 + 2, mid + 1, end, l, r);
    return leftSum + rightSum;
}

int main() {
    int N, K;
    cin >> N >> K;

    tree.resize(4 * N, 0);
    lazy.resize(4 * N, 0);

    for (int i = 0; i < K; i++) {
        int operationType, startIndex, endIndex;
        cin >> operationType >> startIndex >> endIndex;
        endIndex--;
        startIndex--;
        if (operationType == 0) {
            updateRange(0, 0, N - 1, startIndex, endIndex);
        } else {
            cout << queryRange(0, 0, N - 1, startIndex, endIndex) << endl;
        }
    }

    return 0;
}
