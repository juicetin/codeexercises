#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;
int main()
{
	int length;
	cin >> length;
	int score_map[256];
	memset(score_map, 0, sizeof(score_map));
	score_map['a'] = 3;
	score_map['e'] = 3;
	score_map['i'] = 3;
	score_map['o'] = 3;
	score_map['u'] = 3;
	score_map['t'] = 3;
	score_map['z'] = -3;
	score_map['p'] = 1;
	score_map['k'] = 2;
	score_map['s'] = 4;
	
	vector<pair<int, string> > data;

	for (int i = 0; i < length; ++i)
	{
		std::string	tmp;
		cin >> tmp;
		int score = 0;
		for (string::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			score += score_map[*it];
		}
		data.push_back(make_pair(score, tmp));
	}

	for (int i = 0; i < length; ++i)
	{
		//cout << vector[i].get<0> << vector[i].get<1> << endl;
		cout << vector[i]->first << " " << vector[i]-> second << endl;
	}
}

