/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Closest pair of points (Brute - force)
//Time complexity : O(n^2)

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the closest pair of points using a brute-force approach
pair<Point, Point> closestPairBruteForce(vector<Point>& points) {
    int n = points.size();
    double minDist = INT_MAX;
    pair<Point, Point> closestPair;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                closestPair = {points[i], points[j]};
            }
        }
    }

    return closestPair;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);

    cout << "Enter the coordinates of the points:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    pair<Point, Point> closest = closestPairBruteForce(points);

    cout << "Closest pair of points: (" << closest.first.x << ", " << closest.first.y << ") and (" << closest.second.x << ", " << closest.second.y << ")" << endl;
    cout << "Minimum distance: " << distance(closest.first, closest.second) << endl;
        
        //OUTPUT : 
        
        // Enter the number of points: 6
        // Enter the coordinates of the points:
        // Point 1: 2 3
        // Point 2: 12 30
        // Point 3: 40 50
        // Point 4: 5 1
        // Point 5: 12 10
        // Point 6: 3 4
        // Closest pair of points: (2, 3) and (3, 4)
        // Minimum distance: 1.41421

    return 0;
}