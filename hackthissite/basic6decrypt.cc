#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    while(true)
    {
        std::string string;
        puts("Please enter a string to decrypt");
        cin >> string;
        std::string decrypted = string; 
        for (int i = 0; i < string.length(); ++i)
        {
 //           decrypted[2*i] = string[i]; 
 //           decrypted[string.length()-1 - 2*i] = string[string.length()-1 - i] - 7;
              decrypted[i] = string[i] - i; 
        }
        cout << decrypted << endl;
    }
}
