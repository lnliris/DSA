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

Node* findElementFromEnd(List L, int i) {
    if (!L.pHead) {
        cout << "List is empty";
        return NULL;
    }
    
    Node* p = L.pHead;
    for (int j = 1; j <= i-1 ; j++) {
        p = p->next;
        if (!p) {
            cout << "The index is invalid";
            return NULL;
        }
    }

    Node* ithEle = L.pHead;
    while (p != NULL && p->next != NULL) {
        p = p->next;
        ithEle = ithEle->next;
    }
    return ithEle;
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    Node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
