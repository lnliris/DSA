#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int data;
    Node* next;
};

struct List
{
    Node* pHead, * tail;
};

Node* getNode(int x)
{
    Node* p = new Node;

    if (p != NULL)
    {
        p->data = x;
        p->next = NULL;
    }

    return p;
}

void Init(List& L)
{
    L.pHead = L.tail = NULL;
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

void inputList(List& L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        addTail(L, x);
    }
}

void outputList(List L)
{
    if (L.pHead == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        Node* p = L.pHead;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

void outputGreaterThan(List L, int m)
{
    bool found = 0;
    if (!L.pHead)
        cout << "List is empty";
    else
    {
        Node* p = L.pHead;
        while (p)
        {
            if (p->data > m)
            {
                found = true;
                cout << p->data << " ";
            }
            p = p->next;
        }
        if (!found)
            cout << "None";
    }
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
