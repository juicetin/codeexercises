#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
	public:
		Node(int value)
		{
			value_ = value;
		}

		~Node() {}

		int getValue()
		{
			return value_;
		}

		Node *next;

		Node& operator=(const Node *node)
		{
			this->value_ = node->value_;
			//this->next = node->next;
			return *this;
		}

	private:
		int value_;
};

Node *reverseLinkedList(Node *head)
{
	Node *new_head = *&head;
	cout << new_head->getValue() << " " << new_head->next << endl;

	new_head->next = 0;
	Node *original_it = head;
	cout << original_it->next << endl;
	while (original_it->next)
	{
		Node *tmp = *&(original_it->next);
		tmp->next = new_head;
		new_head = tmp;
		cout << new_head->getValue() << " " << new_head->next << endl;
		original_it = original_it->next;
	}
	return new_head;
}

int main()
{
	Node *head = 0;
	Node *iterator = head;
	for (int i = 1; i <= 10; ++i)
	{
		Node *tmp = new Node(i); 
		head->next = tmp;
		head = head->next;
	}

	head = iterator;
	while (iterator->next)
	{
		cout << iterator->getValue() << endl;
		iterator = iterator->next;
	}
	cout << endl;

	Node *reversedHead = reverseLinkedList(head);
	Node *reversed_it = reversedHead;
	//	while (reversed_it->next)
	//	{
	//		cout << reversed_it->getValue() << endl;
	//		reversed_it = reversed_it->next;
	//	}
}
