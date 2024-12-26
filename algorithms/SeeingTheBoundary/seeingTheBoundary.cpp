#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Point;

inline int orientation(const Point& p, const Point& q, const Point& r) {
    if (static_cast<long long>(q.second - p.second) * (r.first - q.first) -
                   static_cast<long long>(q.first - p.first) * (r.second - q.second) == 0) return 0;
    return (static_cast<long long>(q.second - p.second) * (r.first - q.first) -
                   static_cast<long long>(q.first - p.first) * (r.second - q.second) > 0) ? 1 : 2;
}

inline bool segmentsIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) {
    
    if (max(p1.first, q1.first) < min(p2.first, q2.first) ||
        min(p1.first, q1.first) > max(p2.first, q2.first) ||
        max(p1.second, q1.second) < min(p2.second, q2.second) ||
        min(p1.second, q1.second) > max(p2.second, q2.second)) {
        return false;
    }
    if (orientation(p1, q1, p2) != orientation(p1, q1, q2) && orientation(p2, q2, p1) != orientation(p2, q2, q1)) return true;

    if (orientation(p1, q1, p2) == 0 && orientation(p1, q1, q2) == 0) {
        return (min(p2.first, q2.first) <= max(p1.first, q1.first) &&
                min(p1.first, q1.first) <= max(p2.first, q2.first) &&
                min(p2.second, q2.second) <= max(p1.second, q1.second) &&
                min(p1.second, q1.second) <= max(p2.second, q2.second));
    }
    return false;
}

struct QuadTree {
    vector<pair<Point, Point>> segments;
    int minX, minY, maxX, maxY;
    QuadTree *nw, *ne, *sw, *se;
    static const int MIN_SIZE = 64;

    QuadTree(int minX, int minY, int maxX, int maxY) 
        : minX(minX), minY(minY), maxX(maxX), maxY(maxY), nw(nullptr), ne(nullptr), sw(nullptr), se(nullptr) {}

    ~QuadTree() {
        delete nw;
        delete ne;
        delete sw;
        delete se;
    }

    void split() {
        nw = new QuadTree(minX, (minY + maxY) / 2, (minX + maxX) / 2, (minY + maxY) / 2);
        ne = new QuadTree((minX + maxX) / 2, (minY + maxY) / 2, (minX + maxX) / 2, (minY + maxY) / 2);
        sw = new QuadTree(minX, minY, (minX + maxX) / 2, (minY + maxY) / 2);
        se = new QuadTree((minX + maxX) / 2, minY, (minX + maxX) / 2, (minY + maxY) / 2);
    }

    void insert(const Point& p1, const Point& p2) {
        segments.emplace_back(p1, p2);
        
        if (segments.size() > 16 && (maxX - minX) > MIN_SIZE) {  
            if (!nw) split();
            
            int midX = (minX + maxX) / 2;
            int midY = (minY + maxY) / 2;

            
            for (const auto& seg : segments) {
                if (seg.first.first < midX || seg.second.first < midX) {
                    if (seg.first.second > midY || seg.second.second > midY) nw->segments.push_back(seg);
                    if (seg.first.second < midY || seg.second.second < midY) sw->segments.push_back(seg);
                }
                if (seg.first.first > midX || seg.second.first > midX) {
                    if (seg.first.second > midY || seg.second.second > midY) ne->segments.push_back(seg);
                    if (seg.first.second < midY || seg.second.second < midY) se->segments.push_back(seg);
                }
            }
            segments.clear(); 
        }
    }

    bool isBlocked(const Point& start, const Point& end) const {
        for (const auto& seg : segments) {
            if (segmentsIntersect(start, end, seg.first, seg.second)) return true;
        }
        if (!nw) return false;
        int midY = (minY + maxY) / 2;
        if (start.first < (minX + maxX) / 2 || end.first < (minX + maxX) / 2) {
            if (start.second > (minY + maxY) / 2 || end.second > (minY + maxY) / 2)
                if (nw->isBlocked(start, end)) return true;
            if (start.second < (minY + maxY) / 2 || end.second < (minY + maxY) / 2)
                if (sw->isBlocked(start, end)) return true;
        }
        if (start.first > (minX + maxX) / 2 || end.first > (minX + maxX) / 2) {
            if (start.second > (minY + maxY) / 2 || end.second > (minY + maxY) / 2)
                if (ne->isBlocked(start, end)) return true;
            if (start.second < (minY + maxY) / 2 || end.second < (minY + maxY) / 2)
                if (se->isBlocked(start, end)) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, R;
    cin >> N >> R;
    Point farmer;
    cin >> farmer.first >> farmer.second;
    
    QuadTree tree(0, 0, N, N);
    
    for (int i = 0; i < R; ++i) {
        int P;
        cin >> P;
        vector<Point> rock(P);
        for (int j = 0; j < P; ++j) {
            cin >> rock[j].first >> rock[j].second;
        }
        
        for (int j = 0; j < P; ++j) {
            tree.insert(rock[j], rock[(j + 1) % P]);
        }
    }

    int visibleCount = 0;
    
    for (int x = 0; x <= N; ++x) {
        if (!tree.isBlocked(farmer, Point(x, 0))) ++visibleCount;
        if (!tree.isBlocked(farmer, Point(x, N))) ++visibleCount;
    }
    
    for (int y = 1; y < N; ++y) {
        if (!tree.isBlocked(farmer, Point(0, y))) ++visibleCount;
        if (!tree.isBlocked(farmer, Point(N, y))) ++visibleCount;
    }

    cout << visibleCount << endl;
    
    return 0;
}
