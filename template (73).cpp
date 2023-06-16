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
Node* findMaxNode(Tree T)
{
	if (!T || !T->right)
		return T;
	return findMaxNode(T->right);
}
Node* Search(Tree T, int x)
{
	if (!T || T->info == x)
		return T;
	if (T->info < x)
		return Search(T->right, x);
	return Search(T->left, x);
}
void deleteNODE(Tree& T, int x)
{
	if (!T)
		return;
	if (x < T->info)
		deleteNODE(T->left, x);
	else if (x > T->info)
		deleteNODE(T->right, x);
	else
	{
		if (!T->left && !T->right)
		{
			delete T;
			T = NULL;
		}
		else
			if (!T->left)
			{
				Node* temp = T;
				T = T->right;
				delete temp;
			}
			else
				if (!T->right)
				{
					Node* temp = T;
					T = T->left;
					delete temp;
				}
				else
				{
					Node* maxLeftNode = findMaxNode(T->left);
					T->info = maxLeftNode->info;
					deleteNODE(T->left, maxLeftNode->info);
				}
	}
}
void deleteNode(Tree& T, int x)
{
	if (Search(T, x))
	{
		cout << "\nDo you want to delete " << x << "?(y/n):";
		char choose;
		cin >> choose;
		if (choose == 'y' || choose == 'Y')
		{
			deleteNODE(T, x);
		}
	}
	else
		cout << "Not found";
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
