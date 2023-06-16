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
    int* c = new int[right-left+1];

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
            a[left+i] = c[i];
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

int binarySearch(int a[], int n, int l, int r, int item)
{
    int m;

    while (l <= r)
    {
        m = (l + r) / 2;

        if (item == a[m]) return m;

        if (item < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

