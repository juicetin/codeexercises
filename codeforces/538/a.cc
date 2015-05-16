#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib> 
#include <vector>
using namespace std;

int main() 
{
	std::string word;
	std::string want("CODEFORCES"); 
	while (getline(cin, word))
	{
		if (word.find(want) == 0 ||
				((int)word.find(want) >= 0 && 
				(int)word.find(want) == (int)word.length() - (int)want.length()))
		{
			std::cout << "YES" << std::endl;
			continue;
		}

		bool exists = false;
		for (int i = 1; i < want.length(); ++i)
		{
			std::string a = want.substr(0, i);
			std::string b = want.substr(i, want.length());
			
			if (word.find(a) == 0 &&
					word.rfind(b) == word.length() - b.length())
			{
				exists = true;
				break;
			}
		}
		
		if (exists)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
