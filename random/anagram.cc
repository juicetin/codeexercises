/*
Palantir sample/practice test question.
Given two two strings, determine whether
they are anagrams of each other in O(nlogn)
time. This program is O(n), which satisfies
the condition, albeit not strictly.

Uses an int array to hash the two strings
to compare the elements of each in a second
pass.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int char_map[256];
	memset(char_map, 0, sizeof(char_map));

	for (int i = 0; i < a.size(); ++i)
	{
		char_map[a[i]]++;
		char_map[b[i]]--;
	}

	for (int i = 0; i < 256; ++i)
	{
		if (char_map[i] != 0)
		{
			cout << "NO" << endl;
			exit(0);
		}
	}
	
	cout << "YES" << endl;

	return 0;
}
