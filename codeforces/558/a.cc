#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S
{
	int a[2];
};

bool sortCoords(const S &s1, const S &s2)
{
	return s1.a[0] < s2.a[0];
}

int main()
{
	int trees;
	cin >> trees;

	vector<S>coords;
	for (int i = 0; i < trees; ++i)
	{
		int coord, count;
		cin >> coord >> count;
		S s({coord, count});
		coords.push_back(s);
	}

	sort(coords.begin(), coords.end(), sortCoords);

	int neg = 0, pos = 0, neg_max, pos_max;
	for (auto it = coords.cbegin(); it != coords.cend(); ++it)
	{
		if ((*it).a[0] < 0) neg++;
		else pos++;
	}
	if (neg > pos)
	{
		neg_max = pos+1;
		pos_max = pos;
	}
	else 
	{
		pos_max = neg+1;
		neg_max = neg;
	}

	int neg_count = 0, pos_count = 0;
	int sum = 0;
	for (auto it = coords.cbegin(); it != coords.cend(); ++it)
	{
		if ((*it).a[0] < 0 && neg_count < neg_max)
		{
			sum += (*it).a[1];
			neg_count++;
		}
		else if (pos_count < pos_max)
		{
			sum += (*it).a[1];
			pos_count++;
		}
	}

	cout << sum << endl;
}
