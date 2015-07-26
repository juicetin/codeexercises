#include <iostream>
#include <cmath>
using namespace std;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int num_count;
	cin >> num_count;
	int nums[num_count];
	int tmp;
	for (int i = 0; i < num_count; ++i) {
		cin >> tmp;
		nums[i] = tmp;
	}

	int diff;
	if (abs(nums[1]-nums[0]) < abs(nums[2]-nums[1])) {
		diff = nums[1] - nums[0];
	}
	else
	{
		diff = nums[2] - nums[1];
	}

	for (int i = 1; i < num_count; ++i) {
		if (nums[i] - nums[i-1] != diff) {
			cout << nums[i-1] + diff << endl;
			break;
		}
	}

	return 0;
}
