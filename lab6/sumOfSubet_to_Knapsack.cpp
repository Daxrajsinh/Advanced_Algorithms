/*
Name : Daxrajsinh Jadeja
Roll No. : CE052
ID : 21CEUES118
Sem - V
*/

//Sum of Subset using 0/1 knapsack.
#include <bits/stdc++.h>
using namespace std;

bool sumOfSubset(int arr[], int sum, int n, vector<int>& selectedElements) {
    bool m[n + 1][sum + 1] = {0};

    for (int i = 0; i <= n; i++) {
        m[i][0] = true;
    }
    for (int j = 1; j <= sum; j++) {
        m[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= arr[i - 1]) {
                m[i][j] = m[i - 1][j] || m[i - 1][j - arr[i - 1]];
            } else {
                m[i][j] = m[i - 1][j];
            }
        }
    }

    if (!m[n][sum]) {
        return false;  // No subset found
    }

    // Trace back to find selected elements
    int i = n, j = sum;
    while (i > 0 && j > 0) {
        if (m[i][j] && !m[i - 1][j]) {
            selectedElements.push_back(arr[i - 1]);
            j -= arr[i - 1];
        }
        i--;
    }

    return true;
}

int main() {
    int n, t;
    cout << "Provide no. of elements :\n";
    cin >> n;

    int arr[n];
    cout << "Provide an array :\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Provide target sum:\n";
    cin >> t;
    
    vector<int> selectedElements;

    if (sumOfSubset(arr, t, n, selectedElements)) {
        cout << "Yes, it is possible to get the sum.\n";
        cout << "Selected elements: ";
        for (int elem : selectedElements) {
            cout << elem << " ";
        }
        cout << endl;
    } else {
        cout << "No, we don't have any subset that satisfies the given sum.\n";
    }

    return 0;
}
