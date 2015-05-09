#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int seg_count, test_cases;
	cin >> seg_count >> test_cases;
	int	 segments[seg_count];

	int seg_width;
	for (long i = 0; i < seg_count; ++i)
	{
		cin >> segments[i];
	}

	int j, k;
	for (long i = 0; i < test_cases; ++i)
	{
		cin >> j >> k;
		cout << *min_element(segments+j, segments+k+1) << endl;
	}

	return 0;
}