/*
Practice program testing the use of unordered sets.
Purpose of this program is to, given a list of numbers,
determine the number of pairs that have an exact difference
k, which is a given number.

Problem first head of from Daniel Kumar (Palantir phone
interview, stage 2)
*/

#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<int>::const_iterator c_usIter;

int main()
{
	int length, k, tmp_num;
	cin >> length >> k;
	unordered_set<int> nums;
	
	for (int i = 0; i < length; ++i)
	{
		cin >> tmp_num;
		nums.insert(tmp_num);
	}

	int num_pairs = 0;
	for (c_usIter it = nums.begin(); it != nums.end(); ++it)
	{
		c_usIter locate = nums.find(*it - k);
		if (locate != nums.end())
		{
			num_pairs++;
		}
	}
	
	cout << num_pairs << endl;
	return 0;
}