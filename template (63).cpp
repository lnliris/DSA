/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

//###INSERT CODE HERE -
struct Node {
    int val;
    Node* next;
};

struct List {
    Node* head, * tail;
};

void list_initializing(List& l) {
    l.head = l.tail = NULL;
}

Node* getNode(int x)
{
    Node* p = new Node;

    if (p != NULL)
    {
        p->val = x;
        p->next = NULL;
    }

    return p;
}

void add_head(List& L, int x)
{
    Node* p = getNode(x);

    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void add_tail(List& L, int x)
{
    Node* p = getNode(x);

    if (L.tail == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void moveKElements(List& l, int k) {
    if (l.head == NULL || k == 0) {
        return;
    }

    Node* prev = nullptr;
    Node* curr = l.head;
    int count = 1;

    while (curr != nullptr && count < k) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        return;
    }

    prev->next = nullptr;
    l.tail->next = l.head;
    l.head = curr;
    l.tail = prev;
}

void printList(List& l) {
    for (Node* p = l.head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main() {
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    list_initializing(l);

    int option;
    int a, b, k;

    while (true) {
        cin >> option;

        if (option == 0) {
            cin >> a;
            add_head(l, a);
        }
        else if (option == 1) {
            cin >> a;
            add_tail(l, a);
        }
        else if (option == 2) {
            cin >> a >> b;

            Node* curr = l.head;
            Node* prev = nullptr;
            bool found = false;

            while (curr != nullptr) {
                if (curr->val == a) {
                    Node* newNode = new Node;
                    newNode->val = b;
                    newNode->next = curr->next;

                    if (prev == nullptr) {
                        l.head = newNode;
                    }
                    else {
                        prev->next = newNode;
                    }

                    found = true;
                    break;
                }

                prev = curr;
                curr = curr->next;
            }

            if (!found) {
                add_head(l, b);
            }
        }
        else if (option == 3) {
            cin >> k;
            moveKElements(l, k);
        }
        else if (option == 4) {
            break;
        }
    }

    printList(l);

    return 0;
}
