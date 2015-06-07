#include <iostream>

int main()
{
	long long k, n, w;
	std::cin >> k >> n >> w;
	long long ans = k*w*(w+1)/2 - n;
	if (ans > 0)
	{
		std::cout << ans << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
}
