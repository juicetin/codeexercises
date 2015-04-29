#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

using namespace std;
int main(void){

   int flowers, people;
   cin >> flowers >> people;
   int costs[flowers];
   for(int i = 0; i < flowers; i++){
      cin >> costs[i];
   }
   sort(costs, costs + flowers);
   int bought[flowers];
   memset(bought, 0, flowers);
   int buy_pp = flowers/people;
   int total_cost = 0;

   for (int i = 0; i < people; ++i) {
      int bought = 0;
      for (int j = flowers - 1 - i; j >= 0; j -= people) {
         total_cost += (bought+1) * costs[j];
         bought++;
      }
   }

   cout << total_cost << endl;
   return 0;
}
