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

Node* getNode(int x) {
    Node* p = new Node;
    if (p) {
        p->key = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

Node* Search(Tree T, int x) {
    if (T == NULL || T->key == x) {
        return T;
    }
    Node* leftResult = Search(T->left, x);
    if (leftResult != NULL) {
        return leftResult;
    }
    Node* rightResult = Search(T->right, x);
    return rightResult;
}

void SetLeft(Node* node, int x) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        return;
    }
    else {
        node->left = getNode(x);
    }
}

void SetRight(Node* node, int x) {
    if (node == NULL) {
        return;
    }
    if (node->right != NULL) {
        return;
    }
    else {
        node->right = getNode(x);
    }
}


void DeleteLeft(Node* node) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->left == NULL) {
        cout << "Khong co node ben trai\n";
        return;
    }
    Node* temp = node->left;
    if (temp->left == NULL && temp->right == NULL) {
        delete temp;
        node->left = NULL;
    }
    else {
        cout << "Khong la node la nen khong xoa duoc\n";
    }
}

void DeleteRight(Node* node) {
    if (node == NULL) {
        cout << "Node khong ton tai\n";
        return;
    }
    if (node->right == NULL) {
        cout << "Khong co node ben phai\n";
        return;
    }
    Node* temp = node->right;
    if (temp->left == NULL && temp->right == NULL) {
        delete temp;
        node->right = NULL;
    }
    else {
        cout << "Khong la node la nen khong xoa duoc\n";
    }
}

void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
