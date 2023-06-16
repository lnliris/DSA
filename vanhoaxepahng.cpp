#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    list <int> lst;

    vector <list<int>::iterator> p(n + 1);

    for(int i = n; i >= 1; i--)
    {
        lst.push_front(i);
        p[i] = lst.begin();
    }

    for(int i = 1; i <= m; i++)
    {
        int student;
        cin >> student;
        lst.push_front(student);
        lst.erase(p[student]);
        p[student] = lst.begin();
        cout << lst.back() << " ";
    }
}
int main()
{
    solve();
    return 0;
}