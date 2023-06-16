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
void LNR(Tree T)
{
	if (!T) return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}
Node* Search(Tree T, int x)
{
	if (!T || T->info == x)
		return T;
	if (T->info < x)
		return Search(T->right, x);
	return Search(T->left, x);
}

int minValue(Tree T)
{
	while (T->left)
		T = T->left;
	return T->info;
}
int maxValue(Tree T)
{
	while (T->right)
		T = T->right;
	return T->info;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
