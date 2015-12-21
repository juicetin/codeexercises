#include <stdio.h>
#include <cstdio>
using namespace std;

int main() {
	int money = 10;
	int cost = 2;
	int bottles = 0;
	int caps = 0;

	int total = 0;

	bottles += money/cost;
	caps += money/cost;
	total += money/cost;
	while (bottles >= 2 || caps >= 4) {

		int intermediate_total = 0;

		if (bottles >= 2) {
			bottles -= 2;
			intermediate_total += 1;
		}

		if (caps >= 4) {
			intermediate_total += 1;
			caps -= 4;
		}

		total += intermediate_total;
		bottles += intermediate_total;
		caps += intermediate_total;
	}

	printf("%d\n", total);
}
