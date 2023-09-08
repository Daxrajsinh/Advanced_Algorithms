/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//KMP string matching algorithm
//Time complexity : O(n+m)

#include <bits/stdc++.h>
using namespace std;

void findLPS(string P, vector<int> &lps) {
    int m = P.size();
    lps[0] = 0; 
    int k = 0;
    
    for(int q = 1; q < m; q++) { 
        while(k > 0 and P[k] != P[q]) {
            k = lps[k - 1]; 
        }
        
        if(P[k] == P[q]) k++;
        lps[q] = k;
    }
}

int main() {
    string T, P;
    cout << "Enter a Text string :\n";
    cin >> T;
    cout << "Enter a pattern to find :\n";
    cin >> P;
    
    int n = T.size(), m = P.size();
    
    vector<int> lps(m);
    findLPS(P, lps);
    
    int q = 0;
    bool f = 0;
    for(int i = 0; i < n; i++) {
        while(q > 0 and P[q] != T[i]) {
            q = lps[q - 1]; ////using 0 indexed (thats why q - 1),
        }
        
        if(P[q] == T[i]) q++; // next character matches.
        if(q == m) {
            f = 1;
            cout << "Pattern found with shift " << i - m + 1 << endl;  // Corrected the shift value
            q = lps[q - 1];  //look for the next match.
        }
    }
    
    if(!f) cout << "Pattern not found !";
    
    return 0;
}