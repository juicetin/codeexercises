#include <iostream>
#include <cstdio>
using namespace std;

inline void check_num (long long  *n);
inline void check_bigger(long long *a, long long *b, int *swap_check);

int main()
{
    long long a = 0, b = 0;
    while (cin >> a >> b)
    {
        long long largest = 0;
        int swap_check = 0;
        check_bigger(&a, &b, &swap_check);
        for (long long i = a; i <= b; ++i)
        {
            long long test = i, cur_largest = 1;
            while (test != 1)
            {
                check_num(&test);
                cur_largest++;
            }
            if (cur_largest > largest)
            {
                largest = cur_largest;
            }
        }
        if (swap_check == 0)
            printf("%d %d %d\n", a, b, largest);
        else
            printf("%d %d %d\n", b, a, largest);
    }
}

inline void check_num (long long * n)
{
    if (*n % 2 == 0)
    {
        *n = *n/2;
    }
    else
    {
        *n = 3 * (*n) + 1;
    }
}

inline void check_bigger(long long *a, long long *b, int *swap_check)
{
    if (*a > *b)
    {
        long long tmp = *b;
        *b = *a;
        *a = tmp;
        *swap_check = 1;
    }
}
