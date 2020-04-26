#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int main()
{
    ll r;
    ll x, y, nx, ny;
    cin >> r >> x >> y >> nx >> ny;

    ll dx{abs(nx - x)};
    ll dy{abs(ny - y)};

    ld diam = 2L * r;
    ld dist(sqrt(dx * dx + dy * dy * 1L));
    int steps{0};
    while(dist >= 1e-12L)
    {
        ++steps;
        dist -= diam;
    }

    cout << steps << endl;

    return 0;
};

