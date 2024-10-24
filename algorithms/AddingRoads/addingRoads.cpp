#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

struct Link {
    int from, to;
    double length;
};

double computeDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int findGroup(vector<int>& group, int u) {
    return (group[u] == u) ? u : (group[u] = findGroup(group, group[u]));
}

void uniteGroups(vector<int>& group, vector<int>& rank, int u, int v) {
    u = findGroup(group, u);
    v = findGroup(group, v);

    if (rank[u] > rank[v]) {
        group[v] = u;
    } else {
        group[u] = v;
        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }
}

double minimumSpanningTree(const vector<Point>& points, const vector<Link>& links, const vector<pair<int, int>>& existingConnections) {
    int numPoints = points.size();
    vector<int> group(numPoints);
    vector<int> rank(numPoints, 0);
    vector<Link> selectedLinks;

    for (int i = 0; i < numPoints; ++i) {
        group[i] = i;
    }

    for (const auto& connection : existingConnections) {
        int u = connection.first - 1;
        int v = connection.second - 1;
        uniteGroups(group, rank, u, v);
    }

    for (const auto& link : links) {
        int u = link.from;
        int v = link.to;
        if (findGroup(group, u) != findGroup(group, v)) {
            selectedLinks.push_back(link);
            uniteGroups(group, rank, u, v);
        }
    }

    double totalLength = 0.0;
    for (const auto& link : selectedLinks) {
        totalLength += link.length;
    }

    return totalLength;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    cout.tie(NULL);
    int numPoints, numConnections;
    cin >> numPoints >> numConnections;

    vector<Point> points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Link> links;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            Link link;
            link.from = i;
            link.to = j;
            link.length = computeDistance(points[i], points[j]);
            links.push_back(link);
        }
    }

    sort(links.begin(), links.end(), [](const Link& a, const Link& b) {
        return a.length < b.length;
    });

    vector<pair<int, int>> existingConnections(numConnections);
    for (int i = 0; i < numConnections; ++i) {
        cin >> existingConnections[i].first >> existingConnections[i].second;
    }

    double result = minimumSpanningTree(points, links, existingConnections);

    cout << fixed << setprecision(2) << result << endl;

    return 0;
}
