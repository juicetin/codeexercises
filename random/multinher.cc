#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 1) : m_fizz(a) 
	{
		cout << "initialising A..." << endl;
	}

	~A() {}
	void foo() {}
	void bar() {}
	int m_fizz;
};

class B: virtual public A
{
public:
	B(int a = 2)
	{
		A(5);
		foo();
		cout << "initialising B..." << endl;
	}
};

class C: virtual public A
{
public:
	C(int a = 3) : A(a)
	{
		cout << "initialising C..." << endl;
	}
};

class D: public B, public C
{
public:
	D(int a = 4) : A(a)
	{
		cout << "initialising D..." << endl;
	}

	~D();
};

int main()
{
	D *d = new D(9);
	d->foo();
	cout << d->m_fizz << endl;
}
