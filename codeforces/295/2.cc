#include <iostream>
#include <string>
#include <algorithm>

using  namespace std;

int main () {

  string s_1;
  string s_2;
  cin >> s_1 >> s_2;

  int start = atoi(s_1.c_str());
  int end = atoi(s_2.c_str());

  int answer = 0;

  if (start > end)
    answer = start - end;

  if (end > start) {
    while (end > start) {
      start *=2;
      answer++;
    }
    answer += start - end;
  }

  cout << answer;
  return 0;
}
