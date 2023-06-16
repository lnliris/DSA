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
void NLR(Tree T)
{
	if (!T) return;
	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}
Node* findMinNode(Tree T)
{
	if (!T || !T->left)
		return T;
	return findMinNode(T->left);
}
Tree deleteRootNode(Tree T)
{
	if (!T)
		return NULL;
	if (!T->left && !T->right)
	{
		delete T;
		T = NULL;
	}
	else
		if (!T->left)
		{
			Node* temp = T->right;
			delete T;
			return temp;
		}
		else
			if (!T->right)
			{
				Node* temp = T->left;
				delete T;
				return temp;
			}
			else
			{
				Node* temp = findMinNode(T->right);
				T->info = temp->info;
				delete temp;
			}
	return T;
}
void deleteRoot(Tree& T, int m)
{
	for (int i = 0; i <= m; i++)
		T = deleteRootNode(T);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
