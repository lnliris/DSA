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
typedef struct PROVINCE
{
    int id;
    string name;
    int pop;
    float area;
} pro;

struct Node
{
    pro info;
    Node* next;
};

struct List
{
    Node* pHead, * tail;
};

void Init(List& L)
{
    L.pHead = L.tail = NULL;
}

Node* getNode(pro x)
{
    Node* p = new Node;

    if (p != NULL)
    {
        p->info = x;
        p->next = NULL;
    }

    return p;
}

void addTail(List& L, pro x)
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

void inputProvince(pro& p)
{
    cin >> p.id;
    cin.ignore();
    getline(cin, p.name);
    cin >> p.pop;
    cin >> p.area;
}

void outputProvince(pro p)
{
    cout << p.id << "\t" << p.name << "\t" << p.pop << "\t" << p.area << endl;
}

void inputListProvinces(List& L)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        pro p;
        inputProvince(p);
        addTail(L, p);
    }
}

void outputListProvinces(List L)
{
    Node* p = L.pHead;

    if (!p)
    {
        cout << "List is empty";
        return;
    }
    while (p)
    {
        outputProvince(p->info);
        p = p->next;
    }
}

void removeList(List& L)
{
    Node* curr = L.pHead;
    Node* p;

    while (curr)
    {
        p = curr->next;
        delete curr;
        curr = p;
    }

    L.pHead = L.pHead = NULL;
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    if(L.pHead)
    {
        cout<<"Delete all:"<<endl;
        removeList(L);
        outputListProvinces(L);
    }
    return 0;
}




