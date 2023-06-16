/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
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

void init(List& L) {
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

void MySort(List& L) {
	for (Node* p = L.pHead; p != NULL; p = p->next) 
		for (Node* q = L.pHead; q != L.tail; q = q->next) 
			if (q->data > q->next->data) 
				swap(q->data, q->next->data);
}

//Node* findMiddle(List L) {
//	if (!L.head)
//		return NULL;
//	Node* p = L.head, * q = L.head;
//	while (q != NULL && q->next != NULL)
//	{
//		p = p->next;
//		q = q->next->next;
//	}
//	return p;
//}

int MySearch(List &L, int x) {
	Node* left = L.pHead;
	Node* right = L.tail;
	while (left != right) {
		Node* mid = left;
		int dist = 0;
		while (mid != right) {
			mid = mid->next;
			dist++;
		}
	dist /= 2;
	mid = left;
	for (int i = 0; i < dist; i++) {
		mid = mid->next;
	}
	//Node* mid = findMiddle(L);
	if (mid->data == x) {
		int pos = 0;
		for (Node* p = L.pHead; p != mid; p = p->next) {
			pos++;
		}
		return pos;
	} 
	else 
		if (mid->data < x) {
				left = mid->next;
		} 
		else {
				right = mid;
		}
	}
	return -1;
}

int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

