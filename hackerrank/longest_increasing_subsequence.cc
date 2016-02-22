#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_cur_longest(vector<int> arr, vector<int> *LIS, vector<vector<int>> *sub_LIS) {
}

void LIS(vector<int> arr) {
    // vector<vector<int>> sub_LIS;
    // vector<int> LIS;
    vector<int> sub_LIS;
    int LIS = 0;

    // Go through each number in array
    // for (auto it_arr = arr.begin(); it_arr != arr.end(); ++it_arr) {
    for (int i = 0; i < arr.size(); ++i) {
        // int num = *it_arr;
        int num = arr[i];

        // Initial longest list is empty
        // vector<int> cur_LIS;
        int cur_LIS = 0;

        // Find previous LIS whose last value < num
        // for (auto it_this_LIS = sub_LIS.begin(); it_this_LIS != sub_LIS.end(); ++it_this_LIS) {
        for (int j = 0; j < sub_LIS.size(); ++j) {
            int this_LIS = sub_LIS[j];
            // vector<int> this_LIS = *it_this_LIS;

            // int this_LIS_len = this_LIS.size();

            // // Check if previous LIS is longer than current with smaller last value then cur num
            // if (this_LIS_len > 0 && this_LIS.back() < num && 
            //         this_LIS_len > cur_LIS.size()) {
            //     cur_LIS = this_LIS;
            // }
            if (this_LIS > cur_LIS && num > arr[j]) {
                cur_LIS = this_LIS;
            }
        }
        // cur_LIS.push_back(num);
        // sub_LIS.push_back(cur_LIS);
        cur_LIS++;
        sub_LIS.push_back(cur_LIS);

        // if (cur_LIS.size() > LIS.size()) {
        //     LIS = cur_LIS;
        // }
        if (cur_LIS > LIS) {
            LIS = cur_LIS;
        }
    }

    // cout << LIS.size() << endl;
    cout << LIS << endl;
    // for (LIS_item : LIS) {
    //     cout << LIS_item << " ";
    // }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    LIS(arr);
}
