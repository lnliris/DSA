/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int key;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* getNode(int x)
{
    Node* tmp = new Node;

    if (tmp)
    {
        tmp->key = x;
        tmp->left = NULL;
        tmp->right = NULL;
    }

    return tmp;
}

void insertTree(Tree& T, int x)
{
    if (T)
    {
        if (x == T->key)
            cout << "Fail";
        else
            if (x < T->key)
                insertTree(T->left, x);
            else
                insertTree(T->right, x);
    }
    else
        T = getNode(x);
}

void inputTree(Tree& T)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertTree(T, x);
    }
}

int floorValue(Tree T, int x){
    int value = 201;

    while (T != NULL) {
        if (T->key == x) {
            return x;
        }
        else if (T->key > x) {
            T= T->left;
        }
        else {
            value = T->key;
            T = T->right;
        }
    }

    return value;
}

int main() {
    Tree T = NULL;
    inputTree(T);
    int x;
    cin >> x;
    int floorVal = floorValue(T, x);
    cout << floorVal;
    return 0;
}
