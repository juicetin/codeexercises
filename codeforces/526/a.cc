#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int segment_count;
	cin >> segment_count;
	char segment_chars[segment_count];
	cin >> segment_chars;

	bool segments[segment_count];
	for (int i = 0; i < segment_count; ++i)
	{
		if 
			(segment_chars[i] == '.') segments[i] = 0;
		else if 
			(segment_chars[i] == '*') segments[i] = 1;
	}

	for (int i = 1; i <= segment_count/4; ++i)
	{
		for (int j = 0; j < segment_count - (4*i); ++j)
		{
			if (segments[j] == 1 && 
				segments[j+i] == 1 && 
				segments[j+2*i] == 1 && 
				segments[j+3*i] == 1 &&
				segments[j+4*i] == 1)
			{
				cout << "yes\n";
				exit(0); 
			}
		}
	}
	cout << "no\n";	
}