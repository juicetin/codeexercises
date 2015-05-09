#include <iostream>
using namespace std;

char chars[] = {'_','*','_'};

int main()
{
	int lines;
	cin >> lines;
	for (int i = 1; i <= lines; ++i)
	{
		for (int j = 0; j < lines; ++j)
		{
			cout << chars[i%2+j%2];
		}
		cout << endl;
	}
}
