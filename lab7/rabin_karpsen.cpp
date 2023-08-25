/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

// Rabin Karp Algorithm.
#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int p) {
    int res = 1;
    
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res % p;
}

int main() {
    string T, P;
    cout << "Enter a numbered string :\n";
    cin >> T;
    cout << "Enter a numbered pattern to find :\n";
    cin >> P;
    int d, q;
    cout << "Enter the base :\n";
    cin >> d;
    cout << "Enter the modulo :\n";
    cin >> q;
    
    int n = T.size(), m = P.size();
    
    int p = 0, t = 0;
    
    int h = power(d, m-1, q);
        
    for(int i=0; i<m; i++) {
        p = (d * p + (P[i] - '0')) % q;
        t = (d * t + (T[i] - '0')) % q;
    }
    
    bool f = 0;
    
    int j;
    for(int s=0; s<=n-m; s++) {
        if(p == t) {
            for(j=0; j<m; j++) {
                if(P[j] != T[s + j]) break;
            }
            
            if(j == m) {
                cout << "Pattern occurs with shift " << s << endl;
                f = 1;
            }
        }
        
        if(s < n-m) t = (d * ( t - (T[s]-'0')*h ) + (T[s+m] - '0')) % q;
        if(t < 0) t += q;
    }
    
    if(! f) cout << "Pattern not found !" << endl; 
    
    return 0;
}