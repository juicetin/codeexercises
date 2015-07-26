#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 *  * Complete the function below.
 *   */
string LookAndSay(string start, int n) {
	string result;
	for (int x = 0; x < n; ++x)
	{
		result = "";
		char curr = start[0];
		int curr_count = 0;
		for (int i = 0; i < start.length(); ++i)
		{
			if (start[i] == curr)
			{
				curr_count++;
			}
			else
			{
				stringstream ss;
				ss << curr_count;
				string curr_count_s = ss.str();
				result += curr_count_s;
				result += curr;
				curr = start[i];
				curr_count = 1;
			}
		}
		stringstream ss;
		ss << curr_count;
		string curr_count_s = ss.str();
		curr = start[start.length()-1];
		result += curr_count_s;
		result += curr;
		start = result;
	}
	return result;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	string res;
	string _start;
	getline(cin, _start);

	int _n;
	cin >> _n;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	res = LookAndSay(_start, _n);
	cout << res << endl;

	fout.close();
	return 0;
}
