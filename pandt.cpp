#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to represent a point with position and cost
struct Point {
    int x; // Position
    int a; // Cost per unit length
};

// Comparator to sort points by position
bool comparePoints(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of points

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x; // Position of the i-th point
        }
        for (int i = 0; i < n; i++) {
            cin >> points[i].a; // Cost per unit length for the i-th point
        }

        // Sort points by position
        sort(points.begin(), points.end(), comparePoints);

        // Calculate the total minimum cost
        long long totalCost = 0;
        for (int i = 1; i < n; i++) {
            // Cost to connect points[i-1] and points[i]
            long long cost = min(points[i - 1].a, points[i].a) * (long long)(points[i].x - points[i - 1].x);
            totalCost += cost;
        }

        cout << totalCost << '\n'; // Output the result for this test case
    }

    return 0;
}

