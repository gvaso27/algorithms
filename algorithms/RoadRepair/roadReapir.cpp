#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Connection {
    int destination;
    int travelTime;
};

struct NodeInfo {
    int node;
    int changes;
    int distance;

    bool operator>(const NodeInfo& other) const {
        return distance > other.distance;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int totalNodes, totalEdges, maxChanges;
    cin >> totalNodes >> totalEdges >> maxChanges;

    vector<vector<Connection>> graph(totalNodes + 1);

    for (int i = 0; i < totalEdges; ++i) {
        int from, to, time;
        cin >> from >> to >> time;

        graph[from].push_back({to, time});
        graph[to].push_back({from, time});
    }

    vector<vector<int>> distance(totalNodes + 1, vector<int>(maxChanges + 1, INT_MAX));
    distance[1][0] = 0;

    priority_queue<NodeInfo, vector<NodeInfo>, greater<NodeInfo>> pq;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int currentNode = current.node;
        int currentChanges = current.changes;
        int currentDistance = current.distance;

        if (currentDistance > distance[currentNode][currentChanges]) {
            continue;
        }

        for (const auto& neighbor : graph[currentNode]) {
            int to = neighbor.destination;
            int newDistance = currentDistance + neighbor.travelTime;

            if (newDistance < distance[to][currentChanges]) {
                distance[to][currentChanges] = newDistance;
                pq.push({to, currentChanges, newDistance});
            }

            if (currentChanges < maxChanges) {
                int newChangeDistance = currentDistance;
                if (newChangeDistance < distance[to][currentChanges + 1]) {
                    distance[to][currentChanges + 1] = newChangeDistance;
                    pq.push({to, currentChanges + 1, newChangeDistance});
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= maxChanges; ++i) {
        result = min(result, distance[totalNodes][i]);
    }

    cout << result << endl;

    return 0;
}
