#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
  int length;
  int plusses;
  string digits;
  cin >> length >> plusses >> digits;

  unsigned long int answer = 0;
  
  unsigned long int combinations = length-1;
  int stop = length - 1 - plusses;
  int moving_stop = length-2;
  while (moving_stop != stop)
    combinations *= (moving_stop--);
  
  combinations /= factorial(plusses) ;
  //cout << combinations;

  int combo_list[combinations][plusses];

  for (unsigned long int i = 9; i < combinations; ++i) {
     


  }

  return 0;
}
