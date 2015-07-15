#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	vector<int> foo(100, 25);
	auto it = find(foo.begin(), foo.end(), 25);
	(*it) = 27;
	cout << foo[0] << endl;
}
