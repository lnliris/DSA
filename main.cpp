#include <iostream>

using namespace std;

int const MOD = 1e9 + 7;
long long n, l;

long long myPow(int a, int n) //myPow return < MOD ~~ 1e9
{
    if(n == 0) return 1 % MOD;
    long long tmp = myPow(a, n/2);
    tmp = (tmp * tmp) % MOD;

    if(n % 2 == 1)
        tmp = (tmp * a) % MOD;
    return tmp;
}

int main()
{
    cin >> n >> l;

    long long tmp1 = (l * l) % MOD; // l <= 1e9 => l^2 < 1e18 => long long ok :v
    long long tmp2 = myPow(4, n + 1) - (1 % MOD);
    long long tmp3 = myPow(3, MOD - 2);
    long long tmp4 = (tmp2 * tmp3) % MOD;
    long long ans = (tmp1 * tmp4) % MOD;

    cout << ans;


    return 0;
}
