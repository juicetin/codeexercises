#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// Prints a staircase of hashes
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            cout << " ";
        }
        for (int j = 0; j < i+1; ++j) {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}

