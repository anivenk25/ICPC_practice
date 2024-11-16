#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to store position and cost of each point
struct Point {
    int position;
    int cost;
};

// Comparator to sort points based on their position
bool comparePoints(const Point &p1, const Point &p2) {
    return p1.position < p2.position;
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

        // Input positions
        for (int i = 0; i < n; i++) {
            cin >> points[i].position;
        }

        // Input costs
        for (int i = 0; i < n; i++) {
            cin >> points[i].cost;
        }

        // Sort points based on their positions
        sort(points.begin(), points.end(), comparePoints);

        // Calculate the minimum cost to connect all points
        long long totalCost = 0;
        for (int i = 1; i < n; i++) {
            long long distance = points[i].position - points[i - 1].position;
            long long minCost = min(points[i].cost, points[i - 1].cost);
            totalCost += distance * minCost;
        }

        // Output the result for the current test case
        cout << totalCost << '\n';
    }

    return 0;
}

