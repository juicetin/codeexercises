#include <iostream>
#include <cstdio>
#include<gmpxx.h>

/*
 *	A person can hop either 1, 2, or 3 steps at a time up a staircase.
 *	If there are 'N' steps, count the number of ways possible to walk
 *	up this staircase.
 */

mpz_class get_n(int n) {
	mpz_class dp[] = {1, 2, 4};
	if (n <= 3) {
		return dp[n-1];
	}
	long long cur_n = 4;
	while (cur_n < n) {
		mpz_class sum = dp[0] + dp[1] + dp[2];
		dp[0] = dp[1];
		dp[1] = dp[2];
		dp[2] = sum;
		cur_n++;
	}
	return dp[2];
}

int main() {
	long long n = 10000;
	printf("Calculating for n=%ld...\n", n);
	printf("%ld\n", get_n(n));
}
