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
		/*Print YES when the given words STARTS or ENDS with 'CODEFORCES'*/
		if (word.find(want) == 0 ||
				((int)word.find(want) >= 0 && 
				(int)word.find(want) == (int)word.length() - (int)want.length()))
		{
			std::cout << "YES" << std::endl;
			continue;
		}

		bool exists = false;
		/*Build all two-part substrings of 'CODEFORCES' - i.e. C-ODEFORCES,
		 * CO-DEFORCES, COD-EFORCES,..., CODEFORC-ES, CODEFORCE-S
		 * and try and locate them at the beginning and end of the word being
		 * searched respectively. This is because if only one contiguous substring
		 * is to be removed, then if the full word isn't at the ends (as checked
		 * above), then the two parts MUST be on the two ends for the condition
		 * to be satisfied*/
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
