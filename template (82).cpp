/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Tree insertValue(Tree T, int value, bool& isDuplicate) {
    if (T == NULL) {
        return createNode(value);
    }
    if (value < T->key) {
        T->left = insertValue(T->left, value, isDuplicate);
    }
    else if (value > T->key) {
        T->right = insertValue(T->right, value, isDuplicate);
    }
    else {
        isDuplicate = true;
        return T;
    }
    return T;
}

void NLR(Tree T) {
    if (T != NULL) {
        cout << T->key << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    bool isDuplicate = false;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        T = insertValue(T, value, isDuplicate);
        if (isDuplicate) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            return;
        }
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



