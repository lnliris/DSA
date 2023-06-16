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

    while (p)
    {
        outputProvince(p->info);
        p = p->next;
    }
}

bool findProvince(List L, string p)
{
    Node* tmp = L.pHead;

    while (tmp)
    {
        if (tmp->info.name == p)
            return true;

        tmp = tmp->next;
    }

    return false;
}

void insertAfterProvince(List& L, string proName, pro p)
{
    Node* q = L.pHead;

    while (q != NULL && (q->info.name != proName)) 
    {
        q = q->next;
    }

    Node* tmp = getNode(p);

    if (q)
    {
        tmp->next = q->next;
        q->next = tmp;

        if (L.tail == q)
            L.tail = tmp;
    }
}


int main()
{
    List L;
    Init(L);
    inputListProvinces(L);

    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);
    
    cout << "Enter the name to search:" << endl;
    string proName;
    cin.ignore();
    getline(cin, proName);

    if (findProvince(L, proName))
    {
        cout << "Input a new province:" << endl;
        pro p;
        inputProvince(p);
        insertAfterProvince(L, proName, p);

        cout << "Updated List:" << endl;
        cout << "ID\t|Province\t|Population\t|Area" << endl;
        outputListProvinces(L);
    }
    else
        cout << "Not found";
  

    return 0;
}








