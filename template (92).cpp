/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
//###INSERT CODE HERE -

void NLR(Tree T) {
	if (T) {
		cout << T->info << " ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}
Node* getNode(int x)
{
	Node* tmp = new Node;

	if (tmp)
	{
		tmp->info = x;
		tmp->pLeft = NULL;
		tmp->pRight = NULL;
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
				insertTree(T->pLeft, x);
			else
				insertTree(T->pRight, x);
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
void nodesLevel(Tree T, int k, int& count, int curr)
{
	if (!T)
		return;
	if (k == curr) {
		cout << T->info << " ";
		count++;
	}

	nodesLevel(T->pRight, k, count, curr + 1);
	nodesLevel(T->pLeft, k, count, curr + 1);
}
int nodesWithLevel(Tree T, int k, int c)
{
	int count = 0;
	cout << "\nList of nodes with level " << k << " (R->L): ";
	nodesLevel(T, k, count, 0);
	cout << "\nNumber of nodes with level " << k << ": ";
	return count;
}
