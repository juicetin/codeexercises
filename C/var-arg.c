#include <stdio.h>
#include <stdarg.h>

double average ( double num, ...) 
{
	va_list args;
	va_start( args, num );

	double sum = 0;
	for (int x = 0; x < num; ++x) 
	{
		sum += va_arg(args, double);
	}
	va_end(args);

	return sum/num;
}

int main(void) {
	printf("%.20f\n", average(3.0, 4.0, 5.2, 5.3, 8.4));
}
