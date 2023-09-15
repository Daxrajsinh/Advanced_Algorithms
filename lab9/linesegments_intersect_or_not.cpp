/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Check if two line segments intersect or not.
//Time complexity : O(c) - (constant)

#include<bits/stdc++.h>
using namespace std;

typedef struct P {
    int x, y;
} Point;

int direction(Point pi, Point pj, Point pk) {
    return ((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_Segment(Point pi, Point pj, Point pk) {
    return ((min(pi.x, pj.x) <= pk.x and pk.x <= max(pi.x, pj.x)) and (min(pi.y, pj.y) <= pk.y and pk.y <= max(pi.y, pj.y)));
}

bool does_Intersect(Point p1, Point p2, Point p3, Point p4) {
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if( ((d1 > 0 and d2 < 0)or(d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0)or(d3 < 0 and d4 > 0)) ) {
        return true;
    }

    if(d1 == 0 and on_Segment(p3, p4, p1)) return true;
    if(d2 == 0 and on_Segment(p3, p4, p2)) return true;
    if(d3 == 0 and on_Segment(p1, p2, p3)) return true;
    if(d4 == 0 and on_Segment(p1, p2, p4)) return true;

    return false;
}

int main() {
    Point p1, p2, p3, p4;

    cout << "Enter x and y coordinates of p1 :\n";
    cin >> p1.x >> p1.y;

    cout << "Enter x and y coordinates of p2 :\n";
    cin >> p2.x >> p2.y;

    cout << "Enter x and y coordinates of p3 :\n";
    cin >> p3.x >> p3.y;

    cout << "Enter x and y coordinates of p4 :\n";
    cin >> p4.x >> p4.y;
    
    if(does_Intersect(p1, p2, p3, p4)) cout << "YES, they does intersect !\n";
    else cout << "No, They does not intersect !\n";

    return 0;
}