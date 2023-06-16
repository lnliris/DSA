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

Tree insertValue(Tree T, int value) {
    if (T == NULL) {
        return createNode(value);
    }
    if (value < T->key) {
        T->left = insertValue(T->left, value);
    }
    else if (value > T->key) {
        T->right = insertValue(T->right, value);
    }
    return T;
}

void NLR(Tree T) {
    if (T != NULL) {
        cout << T->key << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

Tree rotateRight(Tree T) {
    if (T == NULL) {
        cout << "\nKhong the xoay vi cay rong";
        return T;
    }
    if (T->left == NULL) {
        cout << "\nKhong the xoay phai vi khong co nut con ben trai";
        return T;
    }

    Node* newRoot = T->left;
    T->left = newRoot->right;
    newRoot->right = T;
    return newRoot;
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        T = insertValue(T, value);
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}



