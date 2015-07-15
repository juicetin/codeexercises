#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	// Empty container
	vector<int> a;
	for (int i = 0; i < 10; ++i)
		a.push_back(i);

	// Container copy constructor
	vector<int> b(a);
	auto find_it = b.begin();
	for (auto it = b.begin(); it != b.end(); ++it)
	{
		if ((*it) % 7 == 0)
			find_it = it;
	}

	// Create container by using a range of containers
	vector<int> c(b.begin(), find_it);
	
	// Create 100 copies of 25 on creation
	vector<int> d(100, 25);

	// Create a vector with '47' initialised items
	vector<int> d(47);
}
