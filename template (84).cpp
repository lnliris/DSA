/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Product {
    int id;
    string name;
    string type;
    int year;
    int warranty;
};

struct Node {
    Product key;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* createNode(const Product& key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertTree(Tree& T, const Product& key)
{
    if (T)
    {
        if (key.id == T->key.id)
            return;
        else
            if (key.id < T->key.id)
                insertTree(T->left, key);
            else
                insertTree(T->right, key);
    }
    else
        T = createNode(key);
}

void listProduct(Tree T, const string& type) {
    if (T != NULL) {
        listProduct(T->left, type);
        if (T->key.type == type) {
            cout << T->key.id << "\t" << T->key.name << "\t" << T->key.type << "\t" << T->key.year << "\t" << T->key.warranty << endl;
        }
        listProduct(T->right, type);
    }
}

int countProduct(Tree T, int x) {
    if (T == NULL) {
        return 0;
    }
    int count = 0;
    if (T->key.warranty > x) {
        count = 1;
    }
    count += countProduct(T->left, x) + countProduct(T->right, x);
    return count;
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Product product;
        cin >> product.id;
        cin.ignore();
        getline(cin, product.name);
        getline(cin, product.type);
        cin >> product.year >> product.warranty;
        insertTree(T, product);
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

