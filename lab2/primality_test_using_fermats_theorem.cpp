/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

// Fermat's theorem.
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int power(int a, int x, int n) {
    int res = 1;
    while (x > 0) {
        if (x % 2 == 1)
            res = (res * a) % n;
        x = x / 2;
        a = (a * a) % n;
    }
    return res;
}

bool isprime(int n) {
    int i = 1, k = 100;
    int count = 0;
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;
    while (i <= k) {
        int a = 2 + rand() % (n - 3);
        if (gcd(a, n) != 1)
            return 0;

        if (power(a, n - 1, n) != 1)
            return 0;
        i++;
    }
    return 1;
}

int main() {
    int n;
    cout << "Provide n:\n";
    cin >> n;
    int count = 0;

    srand(time(0));
    
    if (isprime(n))
        cout << "It is prime number" << endl;
    else
        cout << "It is not a prime number" << endl;
    return 0;
}