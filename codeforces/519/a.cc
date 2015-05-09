#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	char line[10];
	int scores[256];
	scores['Q'] = 9;
	scores['q'] = 9;
	scores['R'] = 5;
	scores['r'] = 5;
	scores['B'] = 3;
	scores['b'] = 3;
	scores['N'] = 3;
	scores['n'] = 3;
	scores['P'] = 1;
	scores['p'] = 1;
	scores['K'] = 0;
	scores['k'] = 0;
	scores['.'] = 0;

	int a = '.';
	cout << a << endl;

	int white = 0, black = 0;
	for (int i = 0; i < 8; ++i)
	{
		fgets(line, 10, stdin);
		for (int j = 0; j < 8; ++j)
		{
			if (line[j] >= 97) black += scores[line[j]];	//points for black
			else white += scores[line[j]];					//points for White
		}
	}

	if (white > black) cout << "White" << endl;
	else if (white < black) cout << "Black" << endl;
	else cout << "Draw" << endl;
}