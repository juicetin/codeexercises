#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

struct node {
	struct node *left,*right;
	int val, val1;
};

typedef struct node node;
node * addElement(node * root, int x);
node * addRandomElement (node * root, int x, int index);

/* Write your custom functions here */
int recurse(int &count, node * root) {
	count++;
	int left_count = count;
	int right_count = count;
	if (root->left) {
		recurse(left_count, root->left);
	}
	if (root->right) {
		recurse(left_count, root->right);
	}
	return left_count > right_count ? left_count : right_count;
}
int diameterOfTree(node * root) {
	/* For your reference
	 *   struct node {
	 *      struct node *left,*right;
	 *         int val;
	 *         };
	 *         */
	int count = 0;
	recurse(count, root);
	return count;
}

int main(){

	ofstream fout(getenv("OUTPUT_PATH"));
	node * root = NULL;
	int a[1000],K,i = 0,j = 0;
	int isBst = 0;    
	scanf("%d",&isBst);
	scanf("%d",&K);
	for( j = 0; j < K;j++ ) {
		scanf("%d",&a[i++]);    
	}
	for( i = 0; i < K;i++ ){
		if( !isBst ){            
			root = addRandomElement(root,a[i],i);
		} else {
			root = addElement(root,a[i]);
		}            

	}

	fout << diameterOfTree(root) << endl;
	fout.close();

	return 0;
}

node * addElement(node * root, int x ){
	if( root == NULL ) {
		root = (node *) (malloc(sizeof(node))); 
		root->left = NULL; root->right = NULL;
		root->val = x;root->val1 = -1;
		return root;
	}
	if( x < root->val ) {
		root->left = addElement(root->left,x);
	}
	else {
		root->right = addElement(root->right,x);                            
	}
	return root;
}

node * addRandomElement(node *root, int x, int index){
	if( root == NULL ) {
		root = (node *) (malloc(sizeof(node))); 
		root->left = NULL; root->right = NULL;
		root->val = x;root->val1 = -1;
		return root;
	}

	if( index <=2 ){
		root->left = addRandomElement(root->left,x,index);
	} else {
		root->right = addRandomElement(root->right,x,index);
	}

	return root;
}
