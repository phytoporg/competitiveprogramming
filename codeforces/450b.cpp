#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    ll n;
    int x, y; cin >> x >> y >> n;

    ll mod(1e9 + 7);
    ll ans = vector<int>{
        x,
        y,
        y - x,
        -x,
        -y,
        x - y,
    }[(n - 1) % 6];

    while (ans < 0)
    {
        ans += mod;
    }

    cout << ans % mod << endl;

    return 0;
}

