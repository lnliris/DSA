/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Node* getNode(int x) {
    Node* newNode = new Node;
    newNode->info = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

void insertNode(Tree& T, int x) {
    if (T == NULL) {
        T = getNode(x);
        return;
    }
    if (x < T->info) {
        insertNode(T->pLeft, x);
    }
    else if (x > T->info) {
        insertNode(T->pRight, x);
    }
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(T, x);
    }
}

void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->pLeft);
        cout << T->info << " ";
        LNR(T->pRight);
    }
}

bool isLeaf(Node* node) {
    return (node->pLeft == NULL && node->pRight == NULL);
}

Node* removeLeafs(Tree T) {
    if (T == NULL) {
        return NULL;
    }
    if (isLeaf(T)) {
        delete T;
        return NULL;
    }
    T->pLeft = removeLeafs(T->pLeft);
    T->pRight = removeLeafs(T->pRight);
    return T;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	T = removeLeafs(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"LNR: "; LNR(T);
	return 0;
}



