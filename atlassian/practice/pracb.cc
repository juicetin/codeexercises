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

bool isPrime(int n) {
	if (n == 2) return true;
	else if (n == 1) return false;
	else if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n != i && n % i == 0) return false;
	}
	return true;
}
int getNumberOfPrimes(int n) {
	int numPrimes = 0;
	for (int i = 1; i < n; ++i) {
		if (isPrime(i)) numPrimes++;
	}
	return numPrimes;
}

int main() {
	int res;
	int _n;
	cin >> _n;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

	res = getNumberOfPrimes(_n);
	cout << res << endl;
	
	
	// while(1)
	// {
	// 	int tmp;
	// 	cin >> tmp;
	// 	cout << isPrime(tmp) << endl;
	// }

	return 0;
}
