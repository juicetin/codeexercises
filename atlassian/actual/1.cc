#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class LinkedListNode{
public:
	string val;
	LinkedListNode *next;

	LinkedListNode(string node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, string val){
	if(head == NULL) {
		head = new LinkedListNode(val);
	}
	else {
		LinkedListNode *end = head;
		while (end->next != NULL) {
			end = end->next;
		}
		LinkedListNode *node = new LinkedListNode(val);
		end->next = node;
	}
	return head;
}

/*
 *  * Complete the function below.
 *   */
/*
 * For your reference:
 * LinkedListNode {
 *     string val;
 *         LinkedListNode *next;
 *         };
 *         */
int find(LinkedListNode* list, LinkedListNode* sublist) {
	int index = -1;
	int currIndex = 0;
	bool inSublist = false;
	LinkedListNode* currFull = list;
	LinkedListNode* currSub = sublist;
	while(currFull->next) {
		if (currFull->val.compare(currSub->val) == 0)
		{
			if (!inSublist)
			{
				index = currIndex;
				inSublist = true;
			}
			currSub = currSub->next;
		}
		else
		{
			inSublist = false;
			currSub = sublist;
		}
		currIndex++;
		currFull = currFull->next;
	}
	if (!currSub->next)
	{
		return index;
	}
	return -1;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	int res;

	int _list_size;
	string _list_item;
	LinkedListNode* _list = NULL;
	cin >> _list_size;
	cin.ignore ();
	int _list_i;
	for(_list_i = 0; _list_i < _list_size; _list_i++) { 
		getline(cin, _list_item);
		_list = _insert_node_into_singlylinkedlist(_list, _list_item);
	}


	int _sublist_size;
	string _sublist_item;
	LinkedListNode* _sublist = NULL;
	cin >> _sublist_size;
	cin.ignore ();
	int _sublist_i;
	for(_sublist_i = 0; _sublist_i < _sublist_size; _sublist_i++) { 
		getline(cin, _sublist_item);
		_sublist = _insert_node_into_singlylinkedlist(_sublist, _sublist_item);
	}

	res = find(_list, _sublist);
	cout << res << endl;

	fout.close();
	return 0;
}
