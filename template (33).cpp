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

Node* swapNode(List& L, int x, int y) {
    Node* curX = L.pHead, * prevX = NULL;
    while (curX && curX->info != x) {
        prevX = curX;
        curX = curX->next;
    }
    Node* curY = L.pHead, * prevY = NULL;
    while (curY && curY->info != y) {
        prevY = curY;
        curY = curY->next;
    }
    if (!curX || !curY)
        return NULL;
    if (prevX)
        prevX->next = curY;
    else
        L.pHead = curY;
    if (prevY)
        prevY->next = curX;
    else
        L.pHead = curX;
    swap(curX->next, curY->next);
    return curX;
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

    int x, y; cin>>x>>y;
    Node *p = swapNode(L,x,y); // Tim 2 node chua x va y, Hoan vi 2 node, thay doi cac moi lien ket giua cac node
    /* Tim 2 node chua x va y,
    Hoan vi 2 node do,
    nghia la: Thay doi moi lien ket giua cac node co lien quan, doi cho cac node, gia tri chua trong cac node khong thay doi
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi 2 node khong
    Neu hoan vi node thi node chua x ban dau cung van chua x, gia tri cua node khong thay doi*/
    if(p) // co doi cho
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
