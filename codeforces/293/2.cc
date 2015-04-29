#include <iostream>
#include <string>
using namespace std;

int main () {
  char store1[256];
  char store2[256];
  string s1;
  string s2;
  getline(cin, s1);
  getline(cin, s2);

  int case_diff = 32;

  int yay = 0;
  int whoops = 0;

  for (int i = 0; i < s2.length(); ++i) {
    store2[s2.at(i)]++;		
  }

  for (int i = 0; i < s1.length(); ++i) {
    if (store2[s1.at(i)] > 0) {
      store2[s1.at(i)]--;
      yay++;
      cout << s1.at(i);
    }
    else if (s1.at(i) <= 'Z' && s1.at(i) >= 'A') {
      if (store2[s1.at(i)-case_diff] > 0) {
        store2[s1.at(i)-case_diff]--;
        whoops++;
      }
    }
    else if (s1.at(i) <= 'z' && s1.at(i) >= 'a') {
      if (store2[s1.at(i)+case_diff] > 0) {
        store2[s1.at(i)+case_diff]--;
        whoops++;
      }
    }
  }		
  cout << yay << " " << whoops;
  return 0;
}
