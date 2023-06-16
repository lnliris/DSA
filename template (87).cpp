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

void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->pLeft);
        cout << T->info << " ";
        LNR(T->pRight);
    }
}

Node* Search(Tree T, int x) {
    if (T == NULL || T->info == x) {
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
        //cout << "\nLNR: "; LNR(T); cout << endl;
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
