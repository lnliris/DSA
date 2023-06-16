/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node
{
	int info;
	Node* left, * right;
}; typedef Node* Tree;

Node* getNode(int x)
{
	Node* tmp = new Node;

	if (tmp)
	{
		tmp->info = x;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	return tmp;
};

void insertTree(Tree& T, int x)
{
	if (T)
	{
		if (x == T->info)
			cout << "Fail";
		else
			if (x < T->info)
				insertTree(T->left, x);
			else
				insertTree(T->right, x);
	}
	else
		T = getNode(x);
}

void inputTree(Tree& T)
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		insertTree(T, x);
	}
}
void nodesWithLevel(Tree T, int k)
{
	if (!T)
		return;
	if (k == 0)
		cout << T->info << " ";
	else
	{
		nodesWithLevel(T->right, k - 1);
		nodesWithLevel(T->left, k - 1);
	}
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
