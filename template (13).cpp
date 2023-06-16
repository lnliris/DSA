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

Node* findElement(List L,int i)
{
    if (!L.pHead)
    {
        cout << "List is empty";
        return NULL;
    }
    
    Node* p = L.pHead;
    int count=1;
    
    while (p)
    {
        if (count == i)
            return p;
        p = p->next;
        count++;
    }

    cout << "The index is invalid";
    return NULL;
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
    cout<<"\nThe element at index "<<i<<": ";
    Node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}
