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
    Node* pHead, * pTail;
};

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

    if (L.pTail == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
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

Node* findMiddle(List L) {
    if (!L.pHead)
        return NULL;
    Node* p = L.pHead, * q = L.pHead;
    while (q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    return p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    Node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
