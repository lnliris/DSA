#include <iostream>

using namespace std;

struct Node
{
	int data;
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
		p->data = x;
		p->next = NULL;
	}

	return p;
}

void addHead(List &L,int x)
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
	
	L.pHead = L.tail = NULL;

	int a, x;

	while (1)
	{
		cin >> a;

		if (a == 3) break;
		else 
			if (a == 0)
			{
				cin >> x;
				addHead(L, x);
			}
			else
				if (a == 1)
				{
					cin >> x;
					addTail(L, x);
				}
	}

	outList(L);
}


