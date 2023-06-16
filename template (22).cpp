#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -
void init(DList& L)
{
    L.pHead = L.pTail = NULL;
}

DNode* getNode(int x)
{
    DNode* p = new DNode;

    if (p != NULL)
    {
        p->info = x;
        p->pPrev = p->pNext = NULL;
    }

    return p;
}

void addTail(DList& L, int x)
{
    DNode* newEle = getNode(x);

    if (!L.pHead)
        L.pHead = L.pTail = newEle;
    else
    {
        newEle->pPrev = L.pTail;
        L.pTail->pNext = newEle;
        L.pTail = newEle;
    }
}

void createList(DList& L)
{
    int x;
    while (1)
    {
        cin >> x;
        if (x == -1)
            break;
        else
            addTail(L, x);
    }
}

void printList(DList& L)
{
    if (!L.pHead)
    {
        cout << "List is empty";
        return;
    }

    DNode* p = L.pHead;

    while (p)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void addHead(DList& L, int x)
{
    DNode* newEle = getNode(x);

    if (!L.pHead)
        L.pHead = L.pTail = newEle;
    else
    {
        newEle->pNext = L.pHead;
        L.pHead->pPrev = newEle;
        L.pHead = newEle;
    }
}

void addAfter(DList& L, int x, int y)
{
    DNode* p = L.pHead;

    while (p != NULL && p->info != x) {
        p = p->pNext;
    }
  
    if (p != NULL)
    {
        DNode* newEle = getNode(y);

        newEle->pPrev = p;
        newEle->pNext = p->pNext;

        if (p != L.pTail)
            p->pNext->pPrev = newEle;
        else
            L.pTail = newEle;

        p->pNext = newEle;

    }
    else
        cout << "\nCan't find the value " << x;
}

void addBefore(DList& L, int x, int y)
{
    DNode* p = L.pHead;

    while (p != NULL && p->info != x) {
        p = p->pNext;
    }

    if (p != NULL)
    {
        DNode* newEle = getNode(y);

        newEle->pNext = p;
        newEle->pPrev = p->pPrev;

        if (p != L.pHead)
            p->pPrev->pNext = newEle;
        else
            L.pHead = newEle;
        
        p->pPrev = newEle;
    }
    else 
        cout << "\nCan't find the value " << x;
}

int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
