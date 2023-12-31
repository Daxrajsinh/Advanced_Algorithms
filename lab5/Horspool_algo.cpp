/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Horspool String matching algo. 
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

    // Pre-Processing Stage:
    // Creating Shift Table

    map<char, int> shift;

    for (int i = 0; i < 26; i++) {
        shift[i+'a'] = m;
    }

    for (int i = 0; i <= m - 2; i++) {
        shift[P[i]] = m - 1 - i;
    }

    int j = 0, i;
    bool flag = false;
    while (j + m <= n) {
        i = m - 1;
        while (i >= 0 && P[i] == T[j + i]) {
            i--;
        }
        if (i == -1) {
            cout << "Pattern found at " << j << endl;
            flag = true;
        }
        j += shift[T[j + m - 1]];
    }
    if (!flag)
        cout << "Pattern Not found !";
    return 0;
}
