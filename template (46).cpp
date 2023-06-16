/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct node
{
    int info;
    node* next;
};

struct Stack {
    node* head;
};

void Init(Stack& S)
{
    S.head = NULL;
}
node* getNode(int x) {
    node* p = new node;
    if (p) {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

bool isEmpty(Stack S)
{
    return (!S.head);
}

//bool isFull(Stack S)
//{
//
//}

void Push(Stack& S, int x) 
{
    node* p = getNode(x);

    if (isEmpty(S)) {
        S.head = p;
    }
    else {
        p->next = S.head;
        S.head = p;
    }
}

void Pop(Stack& S)
{
    if (isEmpty(S))
        return;

    node* p = S.head;

    S.head = S.head->next;
    p->next = NULL;

    delete p;
}

void printStack(Stack S)
{
    if (isEmpty(S)) {
        cout << 0;
        return;
    }

    node* p = S.head;
    while (p != NULL)
    {
        cout << p->info;
        p = p->next;
    }
}

void DecimaltoBinary1(int n, Stack& S)
{
    while (n > 0)
    {
        Push(S, n % 2);
        n /= 2;
    }
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

