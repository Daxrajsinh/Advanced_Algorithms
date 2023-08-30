/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Finite Automaton based String matching
//Time complexity : O(M³|Σ|)

#include <bits/stdc++.h>
using namespace std;

int nextState(string P, int m, int state, int x) {
    if(state < m and x == P[state]) {    //If we get the same char x as of pattern, means we are going in right direction
        return state + 1;               //so move to next state.
    }

    int ns, i;  //ns = nextstate.
    //ns will contain longest prefix which is suffix in pattern P, i.e. P[0] to P[state - 1]

    // Start from the largest possible value
    // and stop when you find a prefix which is also suffix.
    for(ns = state; ns > 0; ns--) {
        if(P[ns-1] == x) {
            for(i = 0; i<ns-1; i++) {
                if(P[i] != P[state - ns + i + 1]) break;
            }
            if(i == ns - 1) return ns;
        }
    }
    return 0;
}

int main() {
    string t = "bbaabbabbbaaabba", p = "abba";

    // Output : // Pattern found at index 3
    // Pattern found at index 12
    
    int n = t.size(), m = p.size();

    int T[m+1][256];      //0 to m (i.e. m+1).
    
    //compute Transition function table.
    int s, x;   //s = state.
    for(s = 0; s <= m; s++) {       // 0 to m states
        for(x = 0; x < 256; x++) {    // all possible char states.
            T[s][x] = nextState(p, m, s, x);
        }
    }

    bool f = 0;
    int state = 0; //initially at State 0.
    for(int i=0; i<n; i++) {
        state = T[state][t[i]];
        if(state == m) {
            cout << "Pattern found at index " << i - m + 1 << endl; 
            f = 1;
        }
    }

    if(! f) cout << "Pattern not found" << endl;
    return 0;
}
