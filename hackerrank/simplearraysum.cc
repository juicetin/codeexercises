/*
You are given an array of integers of size NN. Can you find the sum of the elements in the array?

Input 
The first line of input consists of an integer NN. The next line contains NN space-separated integers representing the array elements. 
Sample:

66
11 22 33 44 1010 1111
Output 
Output a single value equal to the sum of the elements in the array. 
For the sample above you would just print 31 since 1+2+3+4+10+11=311+2+3+4+10+11=31.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int sum = 0;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       sum += arr[arr_i];
    }

    cout << sum << endl;
    return 0;
}
