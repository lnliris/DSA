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

void Init(List& L)
{
	L.pHead = L.tail = NULL;
}

void addHead(List& L, int x)
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

void deleteEle(List& L, int x)
{
	if (!L.pHead)
		return;

	if (L.pHead->data == x)
	{
		deleteHead(L);
		return;
	}

	Node* p = L.pHead, * k = NULL;

	while (p != NULL)
	{
		if (p->data == x)
			break;
		k = p;
		p = p->next;
	}
	 // Khong tim thay nut co gia tri bang x
	if (p == NULL)
		return;

	// Xoa nut
	k->next = p->next;
	p->next = NULL;

	// Cap nhat lai tail
	if (p == L.tail)
		L.tail = k;

	delete p;
}

void deleteMultiEle(List& L, int x)
{
	if (!L.pHead)
		return;

	Node* currNode = L.pHead;
	Node* prevNode = NULL;

	while (currNode)
	{
		if (currNode->data == x)
		{
			if (prevNode == NULL)
			{
				L.pHead = currNode->next;
				delete currNode;
				currNode = L.pHead;
			}
			else
			{
				prevNode->next = currNode->next;

				if (currNode == L.tail)
					L.tail = prevNode;

				delete currNode;
				currNode = prevNode->next;
			}
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
	}
}

void insertAfter(List& L, int x, int y)
{
	Node* q = L.pHead;

	while (q != NULL && q->data != x)
	{
		q = q->next;
	}

	Node* p = getNode(y);

	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (L.tail == q)
			L.tail = p;
	}
	else
		addHead(L, y);
}

void outList(List L)
{
	Node* p = L.pHead;

	if (!p)
	{
		cout << "blank";
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
	List L;

	Init(L);

	int a, x, y;

	while (1)
	{
		cin >> a;

		if (a == 6)
			break;
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
				else
					if (a == 2)
					{
						cin >> x >> y;
						insertAfter(L, x, y);

					}
					else
						if (a == 3)
						{
							cin >> x;
							deleteEle(L, x);
						}
						else
							if (a == 4)
							{
								cin >> x;
								deleteMultiEle(L, x);
							}
							else
								deleteHead(L);
	}

	outList(L);
}

