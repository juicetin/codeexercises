#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
	Node (int value) {
		m_value = value;
		m_next = NULL;
	}

	void set_next(Node * next) {
		m_next = next;
	}

	int get_val() {
		return m_value;
	}

	bool has_next() {
		return m_next != NULL;
	}

	Node * get_next() {
		return m_next;
	}

private:
	int m_value;
	Node * m_next;
};

void reverse(Node * linked_list) {
}

int main() {
	Node head_node = Node(0);
	Node * test_linkedlist = &head_node;
	Node * cur_head_node_p = test_linkedlist;
	for (int i = 1; i < 10; ++i) {
		Node next_node = Node(i);
		Node * next_node_p = &next_node;
		cur_head_node_p->set_next(next_node_p);
	}

	reverse(test_linkedlist);

	Node retrieve_linkedlist = *test_linkedlist;
	while (retrieve_linkedlist.has_next()) {
		cout << retrieve_linkedlist.get_val() << endl;
		retrieve_linkedlist = *(retrieve_linkedlist.get_next());
	}
}
