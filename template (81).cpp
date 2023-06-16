/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
->
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//###INSERT CODE HERE -
struct node
{
    int key;
    int value;
};

struct Hash
{
    int m;
    node* hashtable;
    int n;
};

void initHash(Hash& H)
{
    H.m = M;
    H.hashtable = new node[M];
    for (int i = 0; i < H.m; i++)
    {
        H.hashtable[i].key = NULLKEY;
        H.hashtable[i].value = 0;
    }
    H.n = 0;
}

int hashFunction(int key, int m)
{
    return key % m;
}

int linearProbing(int fKey, int j, int m)
{
    return (fKey + j) % m;
}

int quadraticProbing(int fKey, int j, int m)
{
    return (fKey + j * j) % m;
}

void insertHash(Hash& H, int key)
{
    int fKey = hashFunction(key, H.m);
    int j = 0;
    while (j < H.m)
    {
        int index = quadraticProbing(fKey, j, H.m);
        if (H.hashtable[index].key == NULLKEY)
        {
            H.hashtable[index].key = key;
            H.hashtable[index].value = key;
            H.n++;
            return;
        }
        j++;
    }
    cout << "\nBang bam bi day, khong them duoc";
}

void traverseAllHash(const Hash& H)
{
    for (int i = 0; i < H.m; i++)
    {
        if (H.hashtable[i].key != NULLKEY)
        {
            cout << i << " --> " << H.hashtable[i].value << endl;
        }
        else
            cout << i << endl;
    }
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

