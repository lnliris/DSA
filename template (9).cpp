#include <iostream>
using namespace std;

void quickSort(int a[], int l, int r)
{
    int i = l, j = r, x;

    x = a[(l + r) / 2];

    while (i <= j)
    {
        while (a[i] < x)
            i++;

        while (a[j] > x)
            j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);

    if (i < r) quickSort(a, i, r);
}

void sort(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            count++;

    int* c = new int[count], * index = new int[count];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            c[k++] = a[i];
            index[k++] = i;
        }
    }

    quickSort(c, 0, count-1);

    k = 0;

    for (int i = 0; i < count; i++)
        a[index[i]] = c[i];

    delete[] c;
}

int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
