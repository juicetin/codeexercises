#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class A
{
	public:
		A(int value = 0) : m_value(value) {}
		~A() { cout << "Destroy A with value : " << m_value << std::endl; }

		weak_ptr<A> m_ptr;

	private:
		int m_value;
};

class B
{
	public:
		B(int value = 0) : m_value(value) {}
		~B() { cout << "Destroy B with value : " << m_value << std::endl; }

		shared_ptr<B> m_ptr;

	private:
		int m_value;
};

int main()
{
	shared_ptr<A> x (new A(10));
	shared_ptr<A> y (new A(12));

	shared_ptr<B> a (new B(10));
	shared_ptr<B> b (new B(12));

	a->m_ptr = b;
	b->m_ptr = a;

	x->m_ptr = y;
	y->m_ptr = x;
	return 0;
}
