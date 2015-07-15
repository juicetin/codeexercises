class A
{
public:
	A() {}
	void foo() {}
};

class B
{
public:
	B() {}
	virtual void bar() {}
};

class C : public A, public B
{
public:
	C() {}
	void fizz() {}
};

class D
{
public:
	D() {}
	void buzz() {}
};

int main()
{
	B *b = new B();
	//static_cast<C*>(b) -> fizz();
	//reinterpret_cast<D*>(b) -> buzz();
	dynamic_cast<A*>(b) -> foo();
}
