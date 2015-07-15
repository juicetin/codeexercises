#include <iostream>
using namespace std;

class Date
{
	public:
		Date() : m_dummy(0) {}
		Date(const Date &other)
		{
			m_dummy = other.m_dummy;
		}

		Date operator+(int days)
		{
			Date tmp = *this;
			tmp.m_dummy += days;
			cout << "calling member operator+" << endl;
			return tmp;
		}

		Date &operator=(const Date &date)
		{
			m_dummy = date.m_dummy;
			cout << "calling member operator=" << endl;
			return *this;
		}

		Date &operator+=(int days)
		{
			m_dummy += days;
			return *this;
		}

		int getValue() {return m_dummy;}
		void setValue(int value) {m_dummy = value;}
	private:
		int m_dummy;
};



//Date &operator+(Date d, int n)
//{
//	cout << "calling non-member operator+" << endl;
//	return d + n;
//}

Date operator+(int n, Date d)
{
	d += n;
	cout << "calling member opreator+ with swapped args" << endl;
	return d;
}

int main()
{
	Date d;
	Date e = 95+d;
	d = d+3;
	cout << d.getValue() << endl;
	cout << e.getValue() << endl;
}
