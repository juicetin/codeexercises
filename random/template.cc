#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyStack
{
	public:
		MyStack() 
		{
		
		}

		virtual ~MyStack() 
		{
		
		}

		void push(T t) 
		{
			m_vec.push_back(t);	
		}

		void pop() 
		{
			m_vec.erase(m_vec.begin());
		}

		T peek () const 
		{
			return m_vec.front();
		}

		bool empty () const 
		{
			return m_vec.size() > 0;
		}

		int size() const
		{
			return m_vec.size();
		}

	private:
		vector<T> m_vec;
};

int main()
{
	MyStack<double> a;
	a.push(4.0);
	a.push(3.25);
	a.push(9.57);
	while (a.empty() == 1)
	{
		cout << a.peek() << endl;
		a.pop();
	}
}
