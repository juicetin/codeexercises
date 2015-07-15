#include <iostream>
using namespace std;

class Stuff
{
	public:
		Stuff() : m_1(0), m_2(0) {}

		void foo(int &a, int &b) const
		{
			b++;
			a = 5;
		}

		int m_1;
		int m_2;
};

int fizz()
{
	static int a = 67;
	return a;
}

class Qwerty 
{
public:
	Qwerty() {}
};

void asdf (Qwerty&)
{

}

int main()
{
	Stuff bar;
	int a = 3, b = 3;
	bar.foo(a, bar.m_1);
	cout << a << " " << bar.m_1 << endl;

	cout << fizz() << endl;

	const int m = 1;
	const int &n = m;

	const Qwerty zxc;
	asdf(const_cast<Qwerty&>(zxc));
}
