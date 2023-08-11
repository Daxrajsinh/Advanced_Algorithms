/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Naive string matching Approach (Brute-Force) 
//Time complexity : O(nm)
#include <bits/stdc++.h>
using namespace std;

int main() {
    string T, P;
    cout << "Enter a string T :\n";
    cin >> T;

    cout << "Enter a string pattern P :\n";
    cin >> P;

    int n = T.size(), m = P.size();
    int i, j;
    bool flag = 0;
    for (int k = 0; k <= n - m; k++) {
        i = 0, j = 0;
        while (j < m && T[k + i] == P[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << k << endl;
            flag = 1;
        }
    }

    if (!flag)
        cout << "Pattern not found !" << endl;
    return 0;
}
