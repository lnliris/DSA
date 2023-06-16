/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include<cmath>
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
void Nhap(List& L, double heso, int somu) 
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
                /*if (p->somu != 0)
                {
                    cout << "x";
                    if (p->somu != 1)
                    {
                        cout << "^" << p->somu;
                    }
                }*/
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

double TinhDaThuc(List L, double x) {
    Node* curr = L.head;
    double result = 0;

    while (curr != NULL) 
    {
        DONTHUC* p = curr->data;
        result += p->heso * pow(x, p->somu);
        curr = curr->next;
    }

    return result;
}

int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
