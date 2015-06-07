#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	string num;
	cin >> num;
	int dig[] = {-1, -1};
	int divider = 1, index = 0;
	while (divider < atoi(num.c_str()))
	{
		int digit = atoi(num.c_str())/divider%10;
		dig[index++] = digit;
		divider *= 10;
	}

	string units[] = {"one", "two", "three", "four", "five", "six", 
		"seven", "eight", "nine"};
	string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", 
		"sixty", "seventy", "eighty", "ninety"};
	string tens_special[] = {"eleven", "twelve", "thirteen", "fourteen", 
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	int i_num = atoi(num.c_str());
	if (i_num < 10)
	{
		cout << units[i_num-1] << endl;
	}
	else if (i_num > 10 && i_num < 20)
	{
		cout << tens_special[dig[0]-1] << endl;
	}
	else if (i_num % 10 == 0)
	{
		cout << tens[dig[1]-1] << endl;
	}
	else
	{
		cout << tens[dig[1]-1] << "-";
		cout << units[dig[0]-1] << endl;
	}
}

