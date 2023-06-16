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
	Node* pLeft, * pRight;
}; typedef Node* Tree;

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
int findLargest(Tree T) {
	if (T == NULL)
		return -1;
	Node* current = T;
	while (current->pRight != NULL)
		current = current->pRight;
	return current->info;
}

int findSecondLargest(Tree T) {
	if (T == NULL || (T->pLeft == NULL && T->pRight == NULL))
		return -1;

	Node* current = T;
	while (true) {
		if (current->pLeft != NULL && current->pRight == NULL) {
			return findLargest(current->pLeft);
		}
		if (current->pRight != NULL &&
			(current->pRight->pLeft == NULL && current->pRight->pRight == NULL)) {
			return current->info;
		}
		current = current->pRight;
	}
}
void secondLargest(Tree T)
{
	int largest =findSecondLargest(T);
	if (largest != -1)
		cout << "2nd largest value is " << largest;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
