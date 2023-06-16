#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);

//###INSERT CODE HERE -
void merge(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int* c = new int[right - left + 1];

    while (i <= mid && j <= right)
    {
        if (a[i] > a[j])
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
int calculateHIndex(int* citation, int n) {
    MergeSort(citation, 0, n - 1);
    if (citation[n - 1] >= n)
        return n;

    for (int i = 0; i < n; i++)
        if (citation[i] >= i + 1 && citation[i + 1] <= i + 1)
            return i + 1;
        
}


int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;
	//cout << n << endl;
	citation = new int[n];

	for (i = 0; i < n; i++)
		cin >> citation[i];

	cout << calculateHIndex(citation, n);
	return 0;


}

