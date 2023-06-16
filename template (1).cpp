
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
#define MIN -1000
#define MAX 1000

int isTotalOven(int *a, int n) // or (int a[], int n)
{
    for (int i=0;i<n;i++)
        if(a[i]%2!=0)
            return 0;
    return 1;
}
int isValidValue (int *a, int n) // or (int a[], int n)
{
    for (int i=0;i<n;i++)
        if (a[i]<2*MIN||a[i]>2*MAX)
            return 0;
    return 1;
}
int main()
{
//###INSERT CODE HERE -

    int n;
    cin >> n;
    int* a = new int[n];
    srand((int)time(0));
    for (int i = 0; i < n; i++) a[i] = (MIN + rand() % (MAX-MIN+1))*2;
    //for (int i = 1; i < n; i++) cout << a[i] << " ";
    //cout << endl;
    if(isTotalOven(a,n)==1) cout<<"Mang toan so chan"<<endl;
    if (isValidValue(a,n)==1) cout<<"Mang chua cac gia tri nam trong khoang ["<<2*MIN<<","<<2*MAX<<"]";

    return 0;
}


