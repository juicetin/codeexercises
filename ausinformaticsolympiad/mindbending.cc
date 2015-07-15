#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ifstream input("bendin.txt");
	cin.rdbuf(input.rdbuf());
	long a_botl_x, a_botl_y, a_topr_x, a_topr_y;
	long b_botl_x, b_botl_y, b_topr_x, b_topr_y;
	cin >> a_botl_x >> a_botl_y >> a_topr_x >> a_topr_y;
	cin >> b_botl_x >> b_botl_y >> b_topr_x >> b_topr_y;
	
	long area = 0;
	area += (a_topr_x - a_botl_x) * (a_topr_y - a_botl_y);
	area += (b_topr_x - b_botl_x) * (b_topr_y - b_botl_y);

	long x_ol = max((long)0, min(a_topr_x, b_topr_x) - max(a_botl_x, b_botl_x));
	long y_ol = max((long)0, min(a_topr_y, b_topr_y) - max(a_botl_y, b_botl_y));
	area -= x_ol * y_ol;
	
	ofstream output("bendout.txt");
	cout.rdbuf(output.rdbuf());
	cout << area << endl;
}
