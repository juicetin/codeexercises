#include <cmath>
#include <iostream>
using namespace std;

bool isPrime (long long num) 
{
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (long long i = 3; i < sqrt(num); i+= 2) 
	{
		if (num % i == 0) return false;
	}
	return true;
}

long long largestPrimeFactor (long long num) {
	long long largest = 1;
	for (long long i = 1; i < num; ++i)
	{
		if (num % i == 0 && isPrime(i)) largest = i;
	}
	return largest;
}

int main() {
	cout << (largestPrimeFactor(600851475143));
}
