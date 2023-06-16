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
    int data;
    Node* next;
};

struct List {
    Node* pHead, * tail;
};

Node* getNode(int x) {
    Node* p = new Node;
    if (p) {
        p->data = x;
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
        cout << p->data << " ";
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

void moveLastToFront(List& L) {
    if (!L.pHead || !(L.pHead->next))
        return;

    Node* p = L.pHead;

    while (p->next->next)
        p = p->next;

    p->next->next = L.pHead;
    L.pHead = p->next;
    p->next = NULL;
}
int main()
{
    List L;
    L.pHead=L.tail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"updated list after moving the last element to front of l: "<<endl;
    outputList(L);
    return 0;
}
