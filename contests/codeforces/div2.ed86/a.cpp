#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        ll a2 = 2ll * a;

        bool xsign{x >= 0};
        bool ysign{y >= 0};

        ll mincost{0};
        if (xsign == ysign)
        {
            if (a2 <= b)
            {
                mincost = a * (abs(x) + abs(y));
            }
            else
            {
                ll large = x > y ? abs(x) : abs(y);
                ll small = x <= y ? abs(x) : abs(y);

                mincost = b * small + a * (large - small);
            }
        }
        else
        {
            mincost = a * (abs(x) + abs(y));
        }

        cout << mincost << endl;
    }

    return 0;
}
