/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

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
void init(DList& L) {
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

void addAfterMulti(DList& L, int x, int y)
{
    DNode* p = L.pHead;
    bool flag = 0;

    while (p != NULL)
    {
        if (p->info == x)
        {
            DNode* newEle = getNode(y);

            newEle->pPrev = p;
            newEle->pNext = p->pNext;

            if (p != L.pTail)
                p->pNext->pPrev = newEle;
            else
                L.pTail = newEle;

            p->pNext = newEle;

            p = p->pNext;
            flag = 1;
        }
        else
        {
            p = p->pNext;
        }
    }

    if (flag == 0) cout << "\nCan't find the value " << x;
}

void addBeforeMulti(DList& L, int x, int y)
{
    DNode* p = L.pHead;
    bool flag = 0;

    while (p != NULL)
    {
        if (p->info == x)
        {
            DNode* newEle = getNode(y);

            newEle->pNext = p;
            newEle->pPrev = p->pPrev;

            if (p != L.pHead)
                p->pPrev->pNext = newEle;
            else
                L.pHead = newEle;

            p->pPrev = newEle;

            p = p->pNext;
            flag = 1;
        }
        else
        {
            p = p->pNext;
        }
    }

    if (flag == 0) cout << "\nCan't find the value " << x;
}

void removeHead(DList& L)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout << "\nDo you want to delete the first element?(y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        if (L.pHead == L.pTail)
        {
            delete L.pHead;
            L.pHead = L.pTail = NULL;
            cout << "\nThe list becomes empty";
            return;
        }
        else
        {
            DNode* temp = L.pHead;
            L.pHead = L.pHead->pNext;
            L.pHead->pPrev = NULL;
            delete temp;
        }
    }
}

void removeTail(DList& L)
{
    if (L.pHead == NULL)
    {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout << "\nDo you want to delete the last element?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        if (L.pHead == L.pTail)
        {
            delete L.pHead;
            L.pHead = L.pTail = NULL;
            cout << "\nThe list becomes empty";
            return;
        }
        else
        {
            DNode* temp = L.pTail;
            L.pTail = L.pTail->pPrev;
            L.pTail->pNext = NULL;
            delete temp;
        }
    }
}

void removeNode(DList& L, int x)
{
    DNode* current = L.pHead;

    while (current != NULL && current->info != x)
    {
        current = current->pNext;
    }

    if (current == NULL)
    {
        cout << "\nCan't find the value " << x;
        return;
    }

    char choice;
    cout << "\nDo you want to delete " << x << " ?(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        if (current == L.pHead)
        {
            L.pHead = L.pHead->pNext;
            if (L.pHead != NULL)
            {
                L.pHead->pPrev = NULL;
            }
            else
            {
                L.pTail = NULL;
            }
        }
        else if (current == L.pTail)
        {
            L.pTail = L.pTail->pPrev;
            if (L.pTail != NULL)
            {
                L.pTail->pNext = NULL;
            }
            else
            {
                L.pHead = NULL;
            }
        }
        else
        {
            current->pPrev->pNext = current->pNext;
            current->pNext->pPrev = current->pPrev;
        }
        delete current;
    }

    if (!L.pHead)
    {
        cout << "\nThe list becomes empty";
    }
}

void removeMultiNodeS(DList& L, int x)
{
    DNode* current = L.pHead;
    bool flag = 0;

    while (current != NULL)
    {
        if (current->info == x)
        {
            flag = 1;
            break;
        }
        current = current->pNext;
    }

    if (!flag)
    {
        cout << "\nCan't find the value " << x;
        return;
    }

    char choice;
    cout << "\nDo you want to delete " << x << "s ?(y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y')
    {
        DNode* current = L.pHead;
        while (current)
        {
            if (current->info == x)
            {
                flag = 1;
                DNode* temp = current;
                current = current->pNext;

                if (temp == L.pHead)
                {
                    L.pHead = L.pHead->pNext;
                    if (L.pHead != NULL)
                    {
                        L.pHead->pPrev = NULL;
                    }
                    else
                    {
                        L.pTail = NULL;
                    }
                }
                else if (temp == L.pTail)
                {
                    L.pTail = L.pTail->pPrev;
                    if (L.pTail != NULL)
                    {
                        L.pTail->pNext = NULL;
                    }
                    else
                    {
                        L.pHead = NULL;
                    }
                }
                else
                {
                    temp->pPrev->pNext = temp->pNext;
                    temp->pNext->pPrev = temp->pPrev;
                }
                delete temp;
               
            }
            else
                current = current->pNext;
        }
    }

    if (!L.pHead)
    {
        cout << "\nThe list becomes empty";
    }
}

int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
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
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;

        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
