#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, k;
    vector <int> a;

    cin >> n >> c >> k;

    a.resize(n);

    for(int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    /*long long left_to_right = 0;
    long long right_to_left = 0;

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > k) break;
        else
        {
            left_to_right += a[i];
        }
    }

    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i] < c - k + 1) break;
        else
        {
            right_to_left += a[i];
        }
    }

    cout << min(left_to_right, right_to_left) << endl;*/
    a.push_back(0);

    long long sum, MIN=1e14;
    int left, right, j;
    for (int i = 0; i < a.size(); i++) {
        left = a[i];
        j = i;
        right = k + left - 1;
        sum = 0;
        if (right <= c) {
            while (a[j] < right && j < n) {
                sum += a[j];
                j++;
            }
        }
        MIN = min(MIN, sum);
    }

    cout << MIN;

    return 0;
}
