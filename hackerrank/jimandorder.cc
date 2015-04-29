#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int order_count;
	cin >> order_count;
	int orders[order_count][2];
	vector<pair<int, int> > v;

	for (int i = 0; i < order_count; ++i) {
		int start, duration;
		cin >> start >> duration;    
		orders[i][0] = i+1;
		orders[i][1] = start + duration;
    	// v.insert(make_pair(i+1, start+duration));
	}
    	// std::sort(&orders[0][0], &orders[0][0] + 9);		

	for (int i = 0; i < order_count - 1; ++i) {
		for (int j = i + 1; j < order_count; ++j) {
			if (orders[i][1] > orders[j][1]) {
				int index = orders[i][0];
				int end = orders[i][1];
				orders[i][0] = orders[j][0];
				orders [i][1] = orders[j][1];
				orders[j][0] = index;
				orders[j][1] = end;
			}
			if (orders[i][1] == orders[j][1]) {
				if (orders[i][0] > orders[j][0]) {
					int index = orders[i][0];
					int end = orders[i][1];
					orders[i][0] = orders[j][0];
					orders [i][1] = orders[j][1];
					orders[j][0] = index;
					orders[j][1] = end;
				}
			}
		}
	}

	for (int i = 0; i < order_count; ++i) {
		cout << orders[i][0] << " ";
	}

	return 0;
}
