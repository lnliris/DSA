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

Node* createNode(int key) {
    Node* newNode = new Node;
    if (newNode) {
        newNode->key = key;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}
void insertTree(Tree& T, int x) {
    if (T == NULL) {
        T = createNode(x);
        return;
    }
    if (x < T->key) {
        insertTree(T->left, x);
    }
    else if (x > T->key) {
        insertTree(T->right, x);
    }
}
void LNR(Tree T) {
    if (T) {
        LNR(T->left);
        cout << T->key << " ";
        LNR(T->right);
    }
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

bool isFullBinaryTree(Tree T) {
    if (T == NULL) {
        return true;
    }

    if (T->left == NULL && T->right == NULL) {
        return true;
    }

    if (T->left != NULL && T->right != NULL) {
        return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
    }

    return false;
}
int depthOfTree(Tree T) {
    if (!T)
        return 0;
    return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}
//bool isCompleteBinaryTree(Tree T, int index, int count) {
//    if (T == NULL) {
//        return true;
//    }
//    if (index >= count) {
//        return false;
//    }
//    return isCompleteBinaryTree(T->left, 2 * index + 1, count) && isCompleteBinaryTree(T->right, 2 * index + 2, count);
//}
int getNodeCount(Tree T) {
    if (T == NULL) {
        return 0;
    }
    return 1 + getNodeCount(T->left) + getNodeCount(T->right);
}
//bool isCompleteBinaryTree(Tree T)
//{
//    if (!isFullBinaryTree(T)) {
//        return false;
//    }
//    if (!T)
//        return true;
//    int treeHeight = depthOfTree(T);
//    int nodeCount = getNodeCount(T);
//    if (!isCompleteBinaryTree(T, 0, nodeCount))
//        return false;
//    return true;
//
//}
bool isCompleteBinaryTree(Tree T) {
    if (!isFullBinaryTree(T)) 
        return false;
    int nodeCount = getNodeCount(T);
    int treeHeight = depthOfTree(T);
    int expectedNodeCount = (1 << treeHeight) - 1;
    if (nodeCount == expectedNodeCount) {
        return 1;
    }
    return 0;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


