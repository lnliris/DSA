/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int info;
    Node* next;
};

struct List {
    Node* pHead, * tail;
};

void Init(List& L) {
    L.pHead = L.tail = NULL;
}

Node* getNode(int x) {
    Node* p = new Node;
    if (p) {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

void addTail(List& L, int x)
{
    Node* p = getNode(x);

    if (L.tail == NULL)
        L.pHead = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void outputList(List L)
{
    if (!L.pHead) {
        cout << "List is empty";
        return;
    }

    Node* p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

void inputList(List& L, int n)
{
    int x;
    while (n > 0) {
        cin >> x;
        addTail(L, x);
        n--;
    }
}

void concate(List& L1, List &L2) {
    if (!L1.pHead && !L2.pHead) {
        return;
    }

    if (!L1.pHead) {
        L1.pHead = L2.pHead;
        return;
    }
    L1.tail->next = L2.pHead;
}

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
