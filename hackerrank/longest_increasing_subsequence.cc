#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void find_cur_longest(vector<int> arr, vector<int> *LIS, vector<vector<int>> *sub_LIS) {
}

// Find largest value smaller than val
int binary_search(int arr[], int val, int left, int right) {
    // while (right - left > 1) {
    //     int mid_i = (left+right)/2;
    //     if (arr[mid_i] >= val) {
    //         right = mid_i;
    //     } else {
    //         left = mid_i;
    //     }
    // }

    // return right;

    if (right - left <= 1) {
        return right;
    }

    int mid = (right+left)/2;
    if (arr[mid] >= val) {
        right = mid;
        return binary_search(arr, val, left, right);
    } else {
        left = mid;
        return binary_search(arr, val, left, right);
    }
}

void LIS(int arr[], int arr_size) {

    // Value at index 'i' is larger value in sub LIS of length 'i'
    int sub_LIS[arr_size];
    for (int i = 0; i < arr_size; ++i) {
        sub_LIS[i] = 0;
    }

    int LIS = 1;
    sub_LIS[0] = arr[0];

    // Go through each number in array
    for (int i = 1; i < arr_size; ++i) {
        int num = arr[i];

        // If number is smaller than smallest,
        //  replace it
        if (num < sub_LIS[0]) {
            sub_LIS[0] = num;

        // If number is larger than largest, extend list
        } else if (num > sub_LIS[LIS-1]) {
            sub_LIS[LIS++] = num;

        } else {

        // Otherwise, find largest number smaller than current num,
        //  and replace the sub LIS that is one longer than that
            int index = binary_search(sub_LIS, num, 0, LIS-1);
            sub_LIS[index] = num;
        }
        // for (int i : sub_LIS) {
        //     cout << i << " ";
        // } cout << endl;
    }

    // for (int i : sub_LIS) {
    //     cout << i << " ";
    // } cout << endl;
    cout << LIS << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    LIS(arr, n);
}
