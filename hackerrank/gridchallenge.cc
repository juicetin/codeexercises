#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; ++i)
	{
		bool broken = false;
		int size;
		cin >> size;
		string line1, line2;
		cin >> line1;

		if (std::string("iv") < "sm") puts("yes");

		for (int j = 1; j < size; ++j)
		{
			cin >> line2;
			sort(line1.begin(), line1.end());
			sort(line2.begin(), line2.end());

			//WHY IS IT WRONG IF I BREAK AS SOON AS TWO INCOMPATIBLE LINES ARE FOUND?
			for (int k = 0; k < size; ++k)
				if (line1[k] > line2[k])
					broken = true;
			line1 = line2;
		}
		if (broken == false)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}