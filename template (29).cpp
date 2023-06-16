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
struct Node
{
	int data;
	Node* next;
};

struct List
{
	Node* pHead, * tail;
};

void Init(List& L) {
	L.pHead = L.tail = NULL;
}

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
	int x;
	while (n > 0) {
		cin >> x;
		addTail(L, x);
		n--;
	}
}

void outputList(List L)
{
	Node* p = L.pHead;

	if (!p) {
		cout << "List is empty";
		return;
	}

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
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

    return 0;
}
