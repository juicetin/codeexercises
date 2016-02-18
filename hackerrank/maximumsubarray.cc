#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <typeinfo>
#include "maximumsubarray.h"
using namespace std;

void maximum_subarray(std::istream& cin) {
    int items;
    cin >> items;
    int NON_CONT_MAX = 0;
    int CONT_MAX_SO_FAR = 0;
    int CONT_MAX_HERE = 0;
    int MAX = INT_MIN;

    bool exists_zero = false;

    int first;
    cin >> first;
    CONT_MAX_HERE = CONT_MAX_SO_FAR = first;

    if (first > 0) {
        NON_CONT_MAX += first;
    }

    if (first > MAX) { MAX = first; }

    // Get maximum subarray
    for (int i = 1; i < items; ++i) {
        int current;
        cin >> current;

        if (current > MAX) {
            MAX = current;
        }

        if (current >= 0) {
            if (current == 0) { exists_zero = true; }
            NON_CONT_MAX += current;
        }

        CONT_MAX_HERE = max(current, CONT_MAX_HERE + current);
        CONT_MAX_SO_FAR = max(CONT_MAX_SO_FAR, CONT_MAX_HERE);
    }

    // Account for array being all negative and first value being the smallest
    if (exists_zero == false && NON_CONT_MAX == 0) {
        NON_CONT_MAX = MAX;
    }

    cout << CONT_MAX_SO_FAR << " " << NON_CONT_MAX << endl;
}

int main() {
    int cases;
    // std::cout << typeid(cin).name() << endl;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        maximum_subarray(cin);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

