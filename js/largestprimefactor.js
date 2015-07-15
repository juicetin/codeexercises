function largestPrimeFactor (n) {
	var i = 2;
	while (i <= n) {
		if (n % i == 0) {
			n /= i;
		} else {
			i++;
		}
	}
	return i;
}

print(largestPrimeFactor(600851475143));
