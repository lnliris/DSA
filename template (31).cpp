/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct Node
{
	long long data;
	Node* next;
};

struct List
{
	Node* pHead, * tail;
};

Node* getNode(long long x)
{
	Node* p = new Node;

	if (p != NULL)
	{
		p->data = x;
		p->next = NULL;
	}

	return p;
}

void Init(List& L)
{
	L.pHead = L.tail = NULL;
}

void addHead(List& L, long long x)
{
	Node* p = getNode(x);

	if (L.pHead == NULL)
		L.pHead = L.tail = p;
	else
	{
		p->next = L.pHead;
		L.pHead = p;
	}
}

void addTail(List& L, long long x)
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

void deleteTail(List& L)
{
	if (!L.pHead)
		return;

	if (L.pHead == L.tail) {
		L.pHead = L.tail = NULL;
		return;
	}

	Node* p = L.pHead;
	while (p->next!=L.tail) {
		p = p->next;
	}
	
	delete L.tail;
	p->next = NULL;
	L.tail = p;
}

void outList(List L)
{
	Node* p = L.pHead;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main() 
{
	List L;
	Init(L);
	int n;
	char x, y;
	long long z;

	cin >> n;
	while (n > 0) {
		cin >> x >> y >> z;
		if (x == '+') {
			if (y == 'H')
				addHead(L, z);
			else
				addTail(L, z);
		}
		else {
			if (y == 'H')
				deleteHead(L);
			else
				deleteTail(L);
		}
		n--;
	}
	outList(L);
}