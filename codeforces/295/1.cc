#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main () {
  int length;
  cin >> length;

  string word;
  cin >> word;
  transform(word.begin(), word.end(), word.begin(), ::tolower);

  int letters[26];
  for (int i = 0; i < length; ++i) {
    letters[word[i]-97] = 1;    
  }

  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (letters[i] == 1)
      count ++;
  }

  if (count == 26)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
