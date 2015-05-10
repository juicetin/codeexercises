#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int prog_c, line_c, err_c, mod;
	cin >> prog_c, line_c, err_c, mod;
	int err_l[prog_c];
	for (int i = 0; i < prog_c; ++i) cin >> err_l[i];

	int perms[prog_c];
	int distinct_c = 0;
	memset(perms, 0, sizeof(perms));
	perms[prog_c=1] = line_c;
	while (perms[0] != line_c)
	{
					
	}
}
