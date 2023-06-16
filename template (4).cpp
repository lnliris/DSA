#include <iostream>
using namespace std;

void inputArray(int*& a, int& n)
{
    cin >> n;
    a = new int(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int binarySearch2(int a[], int n, int x)
{
    int l = 0, r = n - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (x == a[m])
        {
            for (int i = r; i > m; i--)
                if (a[i] == x) return i;
            return m;
        }
        if (x < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main()
{
    int n, *a = NULL;
    inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)break;
        cout<<binarySearch2(a,n,x)<<endl;

    }

    return 0;
}

