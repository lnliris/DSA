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
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Node* getNode(int x) {
    Node* newNode = new Node;
    newNode->key = x;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}

void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->pLeft);
        cout << T->key << " ";
        LNR(T->pRight);
    }
}

Node* Search(Tree T, int x) {
    if (T == NULL || T->key == x) {
        return T;
    }
    Node* leftResult = Search(T->pLeft, x);
    if (leftResult != NULL) {
        return leftResult;
    }
    Node* rightResult = Search(T->pRight, x);
    return rightResult;
}

void SetLeft(Node* node, int x) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->pLeft != NULL) {
        cout << "Da co node con ben trai" << endl;
    }
    else {
        node->pLeft = getNode(x);
    }
}

void SetRight(Node* node, int x) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->pRight != NULL) {
        cout << "Da co node con ben phai" << endl;
    }
    else {
        node->pRight = getNode(x);
    }
}
bool isBSTUtil(Node* node, int minValue, int maxValue) {
    if (node == NULL) {
        return true;
    }
    if (node->key < minValue || node->key > maxValue) {
        return false;
    }
    return isBSTUtil(node->pLeft, minValue, node->key - 1) && isBSTUtil(node->pRight, node->key + 1, maxValue);
}

bool isBST(Tree T) {
    return isBSTUtil(T, -2e9, 2e9);
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;
    if(isBST(T)) cout<<"\Cay vua tao la cay BST";
    else cout<<"\Cay vua tao khong phai la cay BST";

	return 0;
}
