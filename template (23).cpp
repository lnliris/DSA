/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void merge(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int* c = new int[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        c[k++] = a[i++];
    }

    while (j <= right)
    {
        c[k++] = a[j++];
    }

    for (int i = 0; i < k; i++)
    {
        a[left + i] = c[i];
    }

    delete[] c;
}

void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        merge(a, left, mid, right);

    }
}

int main()
{
    int n;
    cin >> n;

    int* a = new int[n];
    inputArray(a, n);

    MergeSort(a, 0, n - 1);

    int i = 0, ans = 0;

    while (a[i] == ans && i < n)
    {
        i++;
        ans++;
    }

    cout << ans;
}
    


