/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int key;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* createNode(int key) {
    Node* newNode = new Node;
    if (newNode) {
        newNode->key = key;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}
void insertTree(Tree& T, int x) {
    if (T == NULL) {
        T = createNode(x);
        return;
    }
    if (x < T->key) {
        insertTree(T->left, x);
    }
    else if (x > T->key) {
        insertTree(T->right, x);
    }
}
void LNR(Tree T) {
    if (T) {
        LNR(T->left);
        cout << T->key << " ";
        LNR(T->right);
    }
}
void inputTree(Tree& T)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
       // LNR(T);
    }
}

bool isFullBinaryTree(Tree T) {
    if (T == NULL) {
        return true;
    }

    if (T->left == NULL && T->right == NULL) {
        return true;
    }

    if (T->left != NULL && T->right != NULL) {
        return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
    }

    return false;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isFullBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Full Binary Tree";
    else cout<<"\nThe tree is a Full Binary Tree";
	return 0;
}

