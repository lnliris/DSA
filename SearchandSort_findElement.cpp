
#include <iostream>
using namespace std;

void inputArray(int*& a, int& n)
{
    cin >> n;

    a = new int(n + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void findElements(int* a, int n, int& m)
{
    cin >> m;

    int j, x;

    for (int i = 0; i < m; i++) {
        cin >> x;
        j = 0;
        a[n] = x;
        while (a[j] != x) j++;
        if (j < n) cout << j << endl;
        else cout << -1 << endl;
    }
}

int main()
{
    int n, m;

    int* a = NULL;

    inputArray(a, n);

    findElements(a, n, m);

    return 0;
}
