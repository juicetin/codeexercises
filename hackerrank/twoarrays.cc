#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long test_cases;
    cin >> test_cases;

    long long length, k;
    for (long long i = 0; i < test_cases; ++i)
    {
        cin >> length >> k;
        vector<long long> first;
        vector<long long> second;
        long long cur_val;
        for (long long j = 0; j < length; ++j)
        {
            cin >> cur_val;
            first.push_back(cur_val);
        }
        for (long long j = 0; j < length; ++j)
        {
            cin >> cur_val;
            second.push_back(cur_val);
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end(), greater<long long>());

        bool fail = false;
        for (long long j = 0; j < length; ++j)
        {
            if (first[j] + second[j] < k)
            {
                fail = true;
                break;
            }
        }
        if (!fail) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
