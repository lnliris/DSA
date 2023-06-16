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
int countNodes(Tree T)
{
	if (!T)
		return 0;
	return countNodes(T->left) + countNodes(T->right) + 1;
}
int depthOfTree(Tree T)
{
	if (!T)
		return -1;
	return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}
void countEven(Tree T, int& count)
{
	if (!T)
		return;
	if (T->info % 2 == 0)
		count++;
	countEven(T->left, count);
	countEven(T->right, count);
}
void countOdd(Tree T, int& count)
{
	if (!T)
		return;
	if (T->info % 2)
		count++;
	countOdd(T->left, count);
	countOdd(T->right, count);
}
int countPositive(Tree T)
{
	if (!T)
		return 0;
	int count = 0;
	if (T->info > 0)
		count++;
	return count + countPositive(T->right) + countPositive(T->left);
}
int countNegative(Tree T)
{
	if (!T)
		return 0;
	int count = 0;
	if (T->info < 0)
		count++;
	return count + countNegative(T->left) + countNegative(T->right);
}
bool isPrime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
int countPrime(Tree T)
{
	if (!T)
		return 0;
	int count = 0;
	if (isPrime(T->info))
		count++;
	return count + countPrime(T->left) + countPrime(T->right);
}
void listPrime(Tree T)
{
	if (!T)
		return;
	if (isPrime(T->info))
		cout << T->info << " ";
	listPrime(T->left);
	listPrime(T->right);	
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
