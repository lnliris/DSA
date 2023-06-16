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
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
//###INSERT CODE HERE -

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

void NLR(Tree T) {
    if (T != NULL) {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

bool isSquare(int n) {
    for (int i = 1; i * i <= n; i++)
        if (i * i == n)
            return 1;
    return 0;
}

void deleteNode(Tree& T, int x) {
    if (T == NULL) {
        return;
    }
    else if (x < T->info) {
        deleteNode(T->pLeft, x);
    }
    else if (x > T->info) {
        deleteNode(T->pRight, x);
    }
    else {
        Node* p = T;
        if (T->pLeft == NULL) {
            T = T->pRight;
            delete p;
        }
        else if (T->pRight == NULL) {
            T = T->pLeft;
            delete p;
        }
        else {
            Node* q = T->pLeft;
            while (q->pRight != NULL) {
                q = q->pRight;
            }
            T->info = q->info;
            deleteNode(T->pLeft, q->info);
        }
    }
}

void SearchStandFor(Node*& p, Node*& q) {
    if (q->pRight != NULL) {
        SearchStandFor(p, q->pRight);
    }
    else {
        p->info = q->info;
        p = q;
        q = q->pLeft;
    }
}

void deleteSquareNumbers(Tree& T) {
    if (T == NULL) {
        return;
    }
    deleteSquareNumbers(T->pLeft);
    deleteSquareNumbers(T->pRight);
    if (isSquare(T->info)) {
        deleteNode(T, T->info);
    }
}