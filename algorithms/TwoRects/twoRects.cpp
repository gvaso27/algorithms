#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    long x, y;
};

long long calculate_area(long long minX, long long maxX, long long minY, long long maxY) {
    if (minX > maxX || minY > maxY) return 0;
    return (maxX - minX) * (maxY - minY);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long minArea = numeric_limits<long long>::max();

    // Sort points by x
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });

    long long dx = points[points.size() - 1].x - points[0].x;

    // Precompute minY2 and maxY2 from the right side for vertical splits
    vector<long> minYRight(N), maxYRight(N);
    minYRight[N - 1] = maxYRight[N - 1] = points[N - 1].y;
    for (int i = N - 2; i >= 0; --i) {
        minYRight[i] = min(minYRight[i + 1], points[i].y);
        maxYRight[i] = max(maxYRight[i + 1], points[i].y);
    }

    long minY1 = points[0].y, maxY1 = points[0].y;
    
    // Try vertical splits
    for (int i = 0; i < N - 1; ++i) {
        minY1 = min(minY1, points[i].y);
        maxY1 = max(maxY1, points[i].y);

        long long area1 = calculate_area(points[0].x, points[i].x, minY1, maxY1);
        long long area2 = calculate_area(points[i + 1].x, points[N - 1].x, minYRight[i + 1], maxYRight[i + 1]);

        minArea = min(minArea, area1 + area2);
    }

    // Sort points by y
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });

    long long dy = points[points.size() - 1].y - points[0].y;

    // Precompute minX2 and maxX2 from the right side for horizontal splits
    vector<long> minXRight(N), maxXRight(N);
    minXRight[N - 1] = maxXRight[N - 1] = points[N - 1].x;
    for (int i = N - 2; i >= 0; --i) {
        minXRight[i] = min(minXRight[i + 1], points[i].x);
        maxXRight[i] = max(maxXRight[i + 1], points[i].x);
    }

    long minX1 = points[0].x, maxX1 = points[0].x;
    
    // Try horizontal splits
    for (int i = 0; i < N - 1; ++i) {
        minX1 = min(minX1, points[i].x);
        maxX1 = max(maxX1, points[i].x);

        long long area1 = calculate_area(minX1, maxX1, points[0].y, points[i].y);
        long long area2 = calculate_area(minXRight[i + 1], maxXRight[i + 1], points[i + 1].y, points[N - 1].y);

        minArea = min(minArea, area1 + area2);
    }

    cout << (dx * dy) - minArea << endl;

    return 0;
}
