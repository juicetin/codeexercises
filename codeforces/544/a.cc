#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;
int main()
{
	int secs, in = 0;
	string str;
	cin >> secs >> str;
	set<char> unique_c;
	int unique_indices[secs];

	/*Store unique characters in a set*/
	for (int i = 0; i < str.size(); ++i)
	{
		set<char>::const_iterator got = unique_c.find(str[i]);	
		if (got == unique_c.end())
		{
			unique_c.insert(str[i]);
			unique_indices[in++] = i;
			if (in >= secs) break;
		}
	}

	/*Fail if more segments required than unique chars*/
	if (unique_c.size() < secs)
	{
		cout << "NO" << endl;
		exit(0);
	}

	/*Answer. Print from i of prev unique to cur, unless
		they are single chars*/
	cout << "YES" << endl;
	for (int i = 1; i < secs; ++i)
	{
		if (unique_indices[i] - unique_indices[i-1] > 1)
		{
			cout << str.substr(unique_indices[i-1], unique_indices[i]-unique_indices[i-1]) << endl;	
		}
		else
		{
			cout << str[unique_indices[i-1]] << endl;
		}
	}
	cout << str.substr(unique_indices[secs-1], str.size()) << endl;
}
