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
char encoding[] = {'0', 'a', 't', 'l', 's', 'i', 'n'};
string convert(long in) {
	string result;
	while (in != 0)
	{
		result = encoding[in % 7] + result;
		in = in/7;
	}
	return result;
}


int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	string res;
	long _in;
	cin >> _in;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	res = convert(_in);
	cout << res << endl;

	fout.close();
	return 0;
}

