/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
using
###End banned keyword*/
#include <iostream>
#include <tuple>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::get;
using std::tuple;
using std::make_tuple;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


//###INSERT CODE HERE -
tuple<List, List, List> partition(List l, int pivot) 
{
    List l1, l2, l3;
    list_initializing(l1);
    list_initializing(l2);
    list_initializing(l3);

    Node* p = l.head;
    while (p != NULL) {
        if (p->val < pivot) {
            add_tail(l1, p->val);
        }
        else 
            if (p->val == pivot) {
                add_tail(l2, p->val);
            }
            else {
                add_tail(l3, p->val);
            }
        p = p->next;
    }

    return make_tuple(l1, l2, l3);
}
// sai cho nay
void join(List& l, List& ls) 
{
    if (!ls.head)
        return;
    if (!l.head) 
    {
        l.head = ls.head;
        l.tail = ls.tail;
    }
    else 
    {
        l.tail->next = ls.head;
        l.tail = ls.tail;
    }
}

int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) 
            add_tail(l, x);
        else break;
        //std::cout << x << '\n';
    } while(true);

    do{
        cin >> x;
        if (x == 0) break;
       // cout << x << "\n";
        auto ls = partition(l, x);

        xuat(std::get<0>(ls));
        xuat(std::get<1>(ls));
        xuat(std::get<2>(ls));
        
        
        join(l, std::get<0>(ls));
        join(l, std::get<1>(ls));
        join(l, std::get<2>(ls));
        
    } while(true);

    return 0;
}



