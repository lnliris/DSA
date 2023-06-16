
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int isBinary(int **a, int m, int n)
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if(a[i][j]!=0&&a[i][j]!=1) // neu co 1 phan tu khong phai 0 hoac 1 thi khong phai ma tran nhi phan
            return 0;
    return 1;
}

int main()
{
//###INSERT CODE HERE -
    int m, n, i, j;
    cin >> m >> n;
    int **a = new int*[m];
    for (i = 0; i < m; i++) a[i] = new int[n];
    srand((int)time(0));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            a[i][j]= 0 + rand() % (1 - 0 +1 );
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
     if (isBinary(a,m,n)==1) cout<<"Ma tran nhi phan";

    return 0;
}
