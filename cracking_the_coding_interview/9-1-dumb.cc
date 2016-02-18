#include <iostream>
#include <cstdio>
#include <gmpxx.h>

/*
 *	A person can hop either 1, 2, or 3 steps at a time up a staircase.
 *	If there are 'N' steps, count the number of ways possible to walk
 *	up this staircase.
 */

long long dp[] = {1, 2, 4};

long long get_n(int n) {
	if (n <= 3) {
		return dp[n-1];
	}

	return get_n(n-3)+ get_n(n-2) + get_n(n-1);
}

int main() {
	int n = 40;
	printf("Calculating for n=%ld...", n);
	printf("%ld\n", get_n(n));
}
