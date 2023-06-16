#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct Node
{
    int info;
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
        p->info = x;
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
            cout << p->info << " ";
            p = p->next;
        }
    }
}

Node* findMax(List L)
{
    Node* p = L.pHead;
    if (!L.pHead)
    {
        cout << "List is empty";
        return p;
    }

    Node* max = L.pHead;
    while (p)
    {
        if (p->info > max->info)
            max->info = p->info;
        p = p->next;
    }
    return max;
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


    cout<<"\nThe maximum value: ";
    Node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
