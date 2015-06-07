#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	string s, t, ans;
	cin >> s >> t;
	int sl = 0, tl = 0;	
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] - '0' == 1) sl++;
		if (t[i] - '0' == 1) tl++;
	}
	if (abs(sl-tl) % 2 != 0) cout << "impossible" << endl;
	else
	{
		int x = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] - '0' != t[i] - '0')
			{
				if (x % 2 == 0) ans += s[i];
				else ans += t[i];
				x++;
			}
			else
			{
				ans += s[i];
			}
		}
	}
//	if (s.length() > 5)
//	{
//		cout << sl << " " << tl << endl;
//	}
	cout << ans << endl;
}
