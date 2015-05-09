#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int num_count;
	cin >> num_count;

	int nums[100];
	memset(nums, 0, sizeof(nums));
	int read_num;
	for (int i = 0; i < num_count; ++i)
	{
		cin >> read_num;
		nums[read_num]++;
	}

	for (int i = 0; i < 100; ++i)
	{
		if (nums[i] == 1)
		{
			cout << i << endl;
			break;
		}
	}
}