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

void deleteHead(List& L)
{
    if (!L.pHead)
        return;

    Node* p = L.pHead;

    L.pHead = L.pHead->next;
    p->next = NULL;

    delete p;

    if (L.pHead == NULL)
        L.tail = NULL;
}

void removeAProvince(List& L, string name, bool& flag)
{
    if (!L.pHead)
        return;

    if (L.pHead->info.name == name)
    {
        deleteHead(L);
        return;
    }

    Node* p = L.pHead, * k = NULL;

    while (p != NULL)
    {
        if (p->info.name == name)
            break;
        k = p;
        p = p->next;
    }

    if (p == NULL)
    {
        flag = 1;
        cout << "Not found";
        return;
    }

    k->next = p->next;
    p->next = NULL;

    if (p == L.tail)
        L.tail = k;

    delete p;
}


int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);
    if (L.pHead)
    {
        string name;
        cout << "Enter the name of the province you want to delete:\n";
        bool flag = 0;
        cin.ignore();
        getline(cin, name);
        removeAProvince(L, name, flag);
        if (flag == 0)
        {
            cout << "Updated List:\n";
            cout << "ID\t|Province\t|Population\t|Area" << endl;
            outputListProvinces(L);
        }
    }
    return 0;
}









