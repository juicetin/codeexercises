#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> word_count;
	string word;
	for (int i = 0; i < 3; ++i)
	{
		cin >> word;
		++word_count[word];
	}
	for (pair_item : word_count)
	{
		cout << pair_item.first << " " << pair_item.second << endl;
	}
}
