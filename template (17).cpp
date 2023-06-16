#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node
{
	int info;
	Node* left, * right;
}; 
typedef Node* Tree;

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

int countLeafs(Tree T)
{
	if (!T) 
		return 0;

	if (T->left == NULL && T->right == NULL)
		return 1;
	
	return countLeafs(T->left) + countLeafs(T->right);
}

//int countInternalNodes(Tree T)
//{
//	if (!T) 
//		return 0;
//
//	if ((T->left || T->right))
//		return 1;
//
//	return countInternalNodes(T->left) + countInternalNodes(T->right);
//}
//
int countOneChild(Tree T)
{
	if (!T) 
		return 0;

	if ((T->left) && !T->right)
		return countOneChild(T->left) + 1;
	else
		if (!T->left && T->right)
			return countOneChild(T->right) + 1;
		else
			return countOneChild(T->left) + countOneChild(T->right);
}

//int countTwoChildren(Tree T)
//{
//	int count = 0;
//
//	if (!T) 
//		return count;
//
//	if (T->left && T->right)
//		count++;
//
//	countTwoChildren(T->left);
//	countTwoChildren(T->right);
//
//	return count;
//}
//
//int countNodes(Tree T)
//{
//	if (!T) 
//		return 0;
//	
//	int count = 0;
//
//	count++;
//
//	countNodes(T->left);
//	countNodes(T->right);
//}

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

//int countLess(Tree T, int x)
//{
//	int count = 0;
//	
//	if (!T) 
//		return count;
//
//	if (T->info < x)
//		count++;
//
//	countLess(T->left, x);
//	countLess(T->right, x);
//}

//int countBetweenValues(Tree T, int x, int y)
//{
//	int count = 0;
//
//	if (!T) return count;
//
//	if (T->info > x && T->info < y)
//		count++;
//
//	countBetweenValues(T->left, x, y);
//	countBetweenValues(T->right, x, y);
//}

int main()
{
	Tree T = NULL;
	inputTree(T);

    //cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	//cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	//cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	//int x;cout<<"Enter x: ";cin>>x;
	//cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	//int y; cout<<"Enter x,y: ";cin>>x>>y;
	//cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
