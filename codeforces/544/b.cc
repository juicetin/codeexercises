#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

char SL[] = {'L', 'S', 'L'};

int main()
{
	int size, isles;
	cin >> size >> isles;

	int max_isles = size/2 * (size/2 + ceil((float)size/2)) + (size % 2) * ceil((float)size/2);

	if (isles > max_isles)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		int isle_counter = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (isle_counter < isles)
				{
					printf("%c", SL[i%2+j%2]);
					if (SL[i%2+j%2] == 'L')
						isle_counter++;
				}
				else
				{
					printf("S");
				}
			}
			printf("\n");
		}
	}		
}
