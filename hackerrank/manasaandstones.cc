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
		int stones, a, b;
		cin >> stones; cin >> a; cin >> b;
		int answer[stones];

		if (a != b) {
			for (int j = 0; j < stones; ++j)
				answer[j] = (stones - 1 - j) * a + j * b;

			sort(answer, answer + stones);

			for (int j = 0; j < stones; ++j)
				cout << answer[j] << " ";
		}
		else
			cout << (stones-1)*a;
		
		cout << endl;
	}
	return 0;
}