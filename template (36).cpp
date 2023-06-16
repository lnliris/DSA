/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *pHead, *tail;
};

void list_initializing(List &l){
    l.pHead = l.tail = NULL;
}

//###INSERT CODE HERE -
Node* getNode(int x) {
    Node* p = new Node;
    if (p) {
        p->val = x;
        p->next = NULL;
    }
    return p;
}

void add_tail(List& l, int x) {
    Node* p = getNode(x);
    if (!l.pHead)
        l.pHead = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void copy(List l, List& l2) {
    if (!l.pHead)
        l2.pHead = l2.tail = NULL;
    else {
        Node* tmp = l.pHead;
        l2.pHead = new Node;
        l2.pHead->val = tmp->val;
        l2.pHead->next = NULL;
        Node* curNode = l2.pHead;
        tmp = tmp->next;
        while (tmp) {
            curNode->next = new Node;
            curNode = curNode->next;
            curNode->val = tmp->val;
            curNode->next = NULL;
            tmp = tmp->next;
        }
    }
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.pHead, *q = l2.pHead;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
