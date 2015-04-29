#include <iostream>
#include <string>
using namespace std;

int main () {
	string str1;
	string str2;
	string answer;
	getline(cin, str1);
	getline(cin, str2);

	int pos = -1;	
  int run_total = 0;
	int check = 0;

	for (int i = str1.length()-1; i != -1; --i) {
		char char1 = str1.at(i);
		char char2 = str2.at(i);	
	  
		int char_int1 = char1;
		int char_int2 = char2;
		run_total += 	char_int2 - char_int1;

		if (char_int2 - char_int1 > 0 && check == 0) {
			pos = i;
			check = 1;
    }
  }

	if (run_total > 0) {
		answer = str1;
    int temp = str1.at(pos)+1;
    string replace(1, temp);
    answer.replace(pos,1,replace);
    for (int i = 0; i < answer.length()-pos-1; ++i)
      answer.replace(pos+1+i, 1, replace, "a");
	}
	else {
		cout << "No such string";
	}
	

	return 0;
}
