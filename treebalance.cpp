#include <iostream>
#include <cmath>
using namespace std;
class node 
{
	public:
	int data;
	node* left;
	node* right;
	node(int d) 
    {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insert(node* root, int x) 
{
	if (root == NULL) 
    {
	node* tmp = new node(x);
	return tmp;
}

if (x < root->data) 
{
	root->left = insert(root->left , x);
		return root;
	} 
    else 
    {
		root->right = insert(root->right, x);
		return root;
	}
}

node* create() 
{
	node* root = NULL;
	int x;
	cin >> x;
	while (true) 
    {
		if (x == -1) break;
		root = insert(root, x);
		cin >> x;
	}
	return root;
}
int height(node* root) 
{
	if (root == NULL) return 0;
	int leftHt = height(root->left);
	int rightHt = height(root->right);
	int curHt = max(leftHt, rightHt) + 1;
	return curHt;
}
bool balance(node* root) 
{
	if (!root) 
    {
		return true;
	}
	int leftHt = height(root->left);
	int rightHt = height(root->right);
	if (abs(leftHt - rightHt) > 1) 
	return false;
	return balance(root->left) && balance(root->right);
}

int main() 
{
	cout<<"\n********************************";
	cout<<"\n   ***Binary Search Tree***";
	cout<<"\n********************************";
	cout<<"\nInput Tree elements (Root,L,R):\n";
	node* root = create();
	cout<<"\n********************************\n";
	if (balance(root)) 
	{
		cout<<"*Is Balanced--------";
	}
	else 
	{
		cout<<"*Is not Balanced--------";
	}
	cout<<"\n********************************";
	return 0;
}
