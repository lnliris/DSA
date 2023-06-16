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

void LRN(Tree T)
{
	if (!T) return;
	LRN(T->left);
	LRN(T->right);
	cout << T->info << " ";
}

void NLR(Tree T)
{
	if (!T) return;
	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}

void listLeafs(Tree T)
{
	if (!T) return;

	if (T->left == NULL && T->right == NULL)
		cout << T->info<<" ";
	else
	{
		listLeafs(T->left);
		listLeafs(T->right);
	}
}

void listInternalNodes(Tree T, int k)
{
	if (!T) return;

	if ((T->left || T->right) && (k != 0))
		cout << T->info << " ";

	listInternalNodes(T->left, 1);
	listInternalNodes(T->right, 1);
}

void listNodesWithOneChild(Tree T)
{
	if (!T) return;

	if (((T->left)&&!T->right)||(!T->left && T->right))
		cout<<T->info<<" ";

	listNodesWithOneChild(T->left);
	listNodesWithOneChild(T->right);
}

void listNodesWithTwoChildren(Tree T)
{
	if (!T) return;

	if (T->left && T->right)
		cout << T->info << " ";

	listNodesWithTwoChildren(T->left);
	listNodesWithTwoChildren(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0);
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
