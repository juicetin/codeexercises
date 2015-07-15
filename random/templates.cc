#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T> bool compare(T value1, T value2) {return (value1 > value2);}

template <typename C, typename T> void sortInDescOrder(C &container)
{ std::sort(container.begin(), container.end(), compare<T>); }

int main()
{
	std::deque<double> nums;
	for (int i = 0; i <= 10; ++i)
	{
		nums.push_back(i * 1.572);
	}
	sortInDescOrder<deque<double>, double>(nums);
}
