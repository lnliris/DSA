/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;


//###INSERT CODE HERE -
void inputMatrix(int a[50][50], int& n, int& m)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}
void outputMatrix(int a[50][50], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

}
void uniqueElements(int a[50][50], int n, int m)
{
    int max = a[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (max < a[i][j])
                max = a[i][j];
    int* b = new int[max + 1] {};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[a[i][j]]++;
    int k = 0;
    for (int i = 0; i <= max; i++)
        if (b[i] == 1)
        {
            k = 1;
            break;
        }
    if (k == 0) cout << "No unique element in the matrix";
    else
    {
        cout << "Unique elements in the matrix:\n";
        for (int i = 0; i <= max; i++)
            if (b[i] == 1)
            {
                cout << i << " ";
            }
    }
}
int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}



