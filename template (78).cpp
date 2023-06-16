/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int key;
    node* next;
};
struct Hash
{
    node* bucket[MAX];
    int m;
};
void initHash(Hash& H)
{
    for (int i = 0; i < H.m; i++)
        H.bucket[i] = NULL;
}
int hashFunction(int key, int m)
{
    return (key % m);
}
node* getNode(int x)
{
    node* p = new node;

    if (p != NULL)
    {
        p->key = x;
        p->next = NULL;
    }

    return p;
}
void insertHash(Hash& H, int x)
{
    int b = hashFunction(x, H.m);
    node* p = H.bucket[b];
    node* newEle = getNode(x);
    node* q = NULL;
    while (p && p->key < x)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        /*if (!H.bucket[b])
            H.bucket[b] = newEle;
        else
        {
            newEle->next = H.bucket[b];
            H.bucket[b] = newEle;
        }*/
        newEle->next = p;
        H.bucket[b] = newEle;
    }
    else
    {
        newEle->next = q->next;
        q->next = newEle;
    }
  
}
void traverseAllHash(Hash& H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i << ": ";
        node* temp = H.bucket[i];
        while (temp)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

