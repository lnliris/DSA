/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


//###INSERT CODE HERE -
void nhap(List& L, double heso, int somu)
{
    DONTHUC* p = new DONTHUC;
    p->heso = heso;
    p->somu = somu;

    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = L.tail = newNode;
    }
    else
    {
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void Xuat(List L)
{
    Node* curr = L.head;
    bool dau = 1;

    while (curr != NULL)
    {
        DONTHUC* p = curr->data;

        if (p->heso != 0)
        {
            if (!dau && p->heso > 0)
            {
                cout << "+";
            }

            if (p->somu)
            {
                if (p->heso != 1 && p->heso != -1)
                {
                    cout << p->heso;
                }
                else if (p->heso == -1)
                {
                    cout << "-";
                }
                cout << "x";
                if (p->somu != 1)
                {
                    cout << "^" << p->somu;
                }
            }
            else
                cout << p->heso;

            dau = 0;
        }
        curr = curr->next;
    }
    if (dau)
        cout << "0";
}

void Nhap(DATHUC& A)
{
    A.head = A.tail = NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
        cin >> heso >> somu;
        nhap(A, heso, somu);
    }
}

DATHUC Tong2DaThuc(DATHUC A, DATHUC B)
{
    DATHUC result;
    result.head = result.tail = NULL;

    Node* nodeA = A.head;
    Node* nodeB = B.head;

    while (nodeA && nodeB)
    {
        DONTHUC* donthucA = nodeA->data;
        DONTHUC* donthucB = nodeB->data;

        if (donthucA->somu > donthucB->somu)
        {
            nhap(result, donthucA->heso, donthucA->somu);
            nodeA = nodeA->next;
        }
        else if (donthucA->somu < donthucB->somu)
        {
            nhap(result, donthucB->heso, donthucB->somu);
            nodeB = nodeB->next;
        }
        else
        {
            double hesoResult = donthucA->heso + donthucB->heso;
            int somu = donthucA->somu;
            nhap(result, hesoResult, somu);
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
    }

    while (nodeA != NULL)
    {
        DONTHUC* donthucA = nodeA->data;
        nhap(result, donthucA->heso, donthucA->somu);
        nodeA = nodeA->next;
    }

    while (nodeB != NULL)
    {
        DONTHUC* donthucB = nodeB->data;
        nhap(result, donthucB->heso, donthucB->somu);
        nodeB = nodeB->next;
    }

    return result;
}


int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
