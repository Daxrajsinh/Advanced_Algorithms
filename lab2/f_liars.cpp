/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long

int power(int a, int x, int n) {
    int res = 1;
    while (x > 0) {
        if (x % 2) {
            res = (res * a) % n;
        }
        x /= 2;
        a = (a * a) % n;
    }
    return res;
}

int f_liars(int n) {
    if (n <= 1 | n == 4) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return 1;
    }

    int i = 1;
    int cnt = 0;
    for (int a = 2; a < n - 1; a++) {
        if (power(a, n - 1, n) == 1) {
            cnt++;
        }
    }
    return cnt;
}

signed main() {
    // your code goes here
    int n;
    cin >> n;

    int cnt_f_liars = f_liars(n);
    double probability = (double)cnt_f_liars / (n - 3);
    cout << cnt_f_liars << " " << probability << endl;

    return 0;
}
