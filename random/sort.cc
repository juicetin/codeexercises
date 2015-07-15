#include <algorithm>
#include <vector>
#include <iostream>

bool desc(int a, int b)
{
	return a > b;
}

void mySort (std::vector<int> &myVec)
{
	std::sort(myVec.begin(), myVec.end(), desc);
	for (std::vector<int>::const_iterator it = myVec.begin(); it != myVec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
int main()
{
	std::vector<int> a;
	for (int i = 0; i < 10; ++i)
		a.push_back(i);
	mySort(a);
}
