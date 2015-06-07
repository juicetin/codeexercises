#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

void convertToBase(int num, int base)
{
	string answer;
	while (num != 0)
	{
		int next_dig = num % base;
		stringstream ss;
		ss << next_dig;
		answer += ss.str().c_str();
		num /= base;
	}
	for (int i = answer.length()-1; i != -1; --i)
		cout << answer[i];
}

int main(int argc, char **argv)
{
	int num, base;
	cin >> num >> base;
	convertToBase(num, base);
}
