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

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
}

void sort(int a[], int n)
{
    int odd = 0, even=0;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            even++;
        else 
            odd++;

    int* oddArr = new int[odd], * evenArr = new int[even];

    int k = 0, l = 0;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            evenArr[k++] = a[i];
        else
            oddArr[l++] = a[i];

    quickSort(evenArr, 0, even - 1);
    quickSort(oddArr, 0, odd - 1);

    k = 0;
    l = odd-1;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            a[i] = evenArr[k++];
        else
            a[i] = oddArr[l--] ;

    delete[] evenArr;
    delete[] oddArr;

}

int main()
{
	int n;
    cin >> n;
	int* a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);

    cout << "Sorted Array: ";
    printArray(a, n);
}



