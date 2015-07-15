#include <iostream>
using namespace std;

class Colour
{
public:
	Colour(){}
	virtual void say()
	{
		cout << "I'm a generic colour" << endl;
	}
};

class Purple : public Colour
{
public:
	Purple() : Colour() {}
	void say()
	{
		cout << "I'm purple!" << endl;
	}
};

class DarkPurple : public Purple
{
public:
	DarkPurple() {}
	void say()
	{
		cout << " I'm a DARK purple..." << endl;
	}
};

int main()
{
	Colour *a = new DarkPurple();
	a->say();
}

