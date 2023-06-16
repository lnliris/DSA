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

Node* findNode(List L, int x) {
    Node* p = L.pHead;
   /* while (p->info != x && p != NULL)
        p = p->nextNode;
    return p; */
    while (p) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

Node* swapData(List& L, int x, int y) {
    Node* p = L.pHead, * p1 , * p2;
    p1 = findNode(L, x);
    p2 = findNode(L, y);
    if (!p1 || !p2) {
        return NULL;
    }
    swap(p1->info, p2->info);
    return p1;
}

int main()
{
    List L;
    L.pHead=L.tail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    Node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
