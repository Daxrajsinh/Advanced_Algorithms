/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Graham's algorithm to find Convex Hull points.
//Time complexity : O(c) - (constant)

#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265

typedef struct P {
    int x, y;
} Point;

float polar_angle(Point p1, Point p2) {
    int dy = p1.y - p2.y;
    int dx = p1.x - p2.x;
    float deg = atan2(dy, dx) * 180.0 / PI;

    if (deg < 0) deg += 180;
    return deg;
}

int main() {
    int n;
    cout << "Enter a no. of points :\n";
    cin >> n;

    vector<Point> pts(n);

    for(int i=0; i<n; i++) {
        cout << "Enter x and y coordinates of Point " << i+1 << endl;
        cin >> pts[i].x >> pts[i].y;
    }

    //finding Point P0 (initial point).
    Point p0 = pts[0];
    int ind = 0;
    for(int i=1; i<n; i++) {
        if(p0.y == pts[i].y) {
            if(p0.x > pts[i].x) {
                p0 = pts[i];
                ind = i;
            } 
        } else if(p0.y > pts[i].y) {
            p0 = pts[i];
            ind = i;
        }
    }

    pts.erase(pts.begin() + ind);  // removing that point from vector to look out for remaining elements
    n--;

    //sorting using polar angle.
    vector<pair<float, Point>> v;

    for(int i=0; i<n; i++) {
        v.push_back({polar_angle(p0, pts[i]), pts[i]});
    }

    sort(v.begin(), v.end());

    for(auto i: v) cout << i.first << endl;

    return 0;
}