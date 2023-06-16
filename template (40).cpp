/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
new
delete
using
###End banned keyword*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *pHead, *tail;
    int x;
};

void list_initializing(List &l){
    l.pHead = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.pHead == NULL){
        l.pHead = l.tail = p;
    } else {
        l.tail->next = p;   
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.pHead; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -
void print_longest_increasing_sub_list(List l) {
    int max = 1, len = 1;
    for (Node* node = l.pHead; node->next != NULL; node = node->next) {
        if (node->val <= node->next->val) {
            len++;
        }
        else {
            if (max < len)
                max = len;
            len = 1;
        }
    }
    if (max < len)
        max = len;
    cout << max;
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l;

    list_initializing(l);
    int x;
    do{
        cin >> x;
        if (x != -1) add_tail(l, x);
        else break;
    } while(true);

    print_longest_increasing_sub_list(l);


    return 0;
}
