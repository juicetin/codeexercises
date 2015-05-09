//UNFINISHED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

unsigned long long choose(unsigned long long n, unsigned long long k)
{
	if (k > n)
	{
		return 0;
	}

	unsigned long long r = 1;
	for (unsigned long long d = 1; d <= k; ++d)
	{
		r *= n--;
		r /= d;
	}
	return r;
}

int main()
{
	int dummy;
	for (int i = 0; i < 26; ++i) cin >> dummy;

	string letters;
	cin >> letters;

	unsigned long long letter_hash[26];
	memset(letter_hash, 0, sizeof(letter_hash));
	for (string::const_iterator it = letters.begin(); it != letters.end(); ++it)
	{
		letter_hash[*it-97]++;
	}

	unsigned long long answer = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (letter_hash[i] > 2)
		{
			if (letter_hash[i] == 3)
			{
				answer += 2;
			}
			else
			{
				//WRONG - this assumes all identical letters are adjacent zzz
				unsigned long long length = letter_hash[i];
				answer += (length-2) * (2 + length - 1) / 2;

				
			}
		}
	}

	cout << answer << endl;
}