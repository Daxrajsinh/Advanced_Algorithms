/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Graham's algorithm to find Convex Hull points.
//Time complexity : O(nlogn) - (constant)

#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265

typedef struct P {
    int x, y;
} Point;

Point p0;

bool compareByFirstElement(const pair<float, Point>& a, const pair<float, Point>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        // If angles are equal, compare by distance
        int dx1 = a.second.x - p0.x;
        int dy1 = a.second.y - p0.y;
        int dx2 = b.second.x - p0.x;
        int dy2 = b.second.y - p0.y;
       
        return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);
    }
}

float polar_angle(Point p0, Point p1) {
    //handling these cases differently, coz they're giving wrong ans.
    if(p0.x == p1.x) return 90;
    if(p0.y == p1.y) return 0;
   
    int dy = p1.y - p0.y;
    int dx = p1.x - p0.x;
   
    float radian_angle = atan((float)dy / dx);
   
    // If the angle is negative, add π radians (or 180 degrees) to make it positive
    if (radian_angle < 0) radian_angle += PI;

    // Convert radians to degrees
    float deg = radian_angle * 180.0 / PI;

    return deg;
}

int direction(Point pi, Point pj, Point pk) {
    return ((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

int main() {
    int n;
    cout << "Enter a no. of points :\n";
    cin >> n;
   
    if (n < 3) {
        cout << "Convex hull cannot be computed with less than 3 points." << endl;
        return 0;
    }
   
    vector<Point> pts(n);

    for(int i=0; i<n; i++) {
        cout << "Enter x and y coordinates of Point :" << i+1 << endl;
        cin >> pts[i].x >> pts[i].y;
    }

    //finding Point P0 (initial point).
    p0 = pts[0];
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
   
    sort(v.begin(), v.end(), compareByFirstElement);
    // cout << p0.x << "," << p0.y << endl;
    // for(auto i: v) cout << i.first << " " << i.second.x << "," << i.second.y << endl;
   
    stack<Point> st;
   // Push the initial points onto the stack.
    st.push(p0);
    st.push(v[0].second);
    st.push(v[1].second);
   
    Point next_to_top = v[0].second, top = v[1].second;
    // Start the loop from i = 2
    for (int i = 2; i < n; i++) {
        while (!st.empty() && direction(next_to_top, top, v[i].second) >= 0) {
            st.pop();
            top = st.top();
            st.pop();
            next_to_top = st.top();
            st.push(top);
        }
        st.push(v[i].second);
       
        //making top and next_to_top for next iteration.
        top = st.top();
        st.pop();
        next_to_top = st.top();
        st.push(top);
    }
    cout << "Convex Hull points :\n";
    while(! st.empty()) {
        cout << st.top().x << "," << st.top().y << endl;
        st.pop();
    }
    
    // o/p :
    // Convex Hull points :
    // -1,3
    // 1,2
    // 3,1
    // 0,5
    // 0,0
    
    return 0;
}
