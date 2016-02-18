#include<iostream>
#include <string>

using namespace std;

string splitInParts(string s, int len) {
	string split = string("");
	int i;
	for (i = 0; i + len < s.length(); i+= len) {
		split += s.substr(i, len) + ' ';
	}

	if (i + len >= s.length()) {
		split += s.substr(i, s.length());
	}

	return split;
}

int main() {
	cout << "[" << splitInParts("abcdefghijklmnopqrstuvwxyz", 2) << "]" << endl;
}
