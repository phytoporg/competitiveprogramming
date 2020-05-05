#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int maxDepth{0};
ll next(ll x, int depth = 0, bool c = false)
{
    if (!x && !c)
    {
        return 0;
    }

    ll d = x % 10;
    ll dOld{d};

    if (c)
    {
        if (d < 4) { d = 4; c = false; }
        else if (d < 7) { d = 7; c = false; }
        else { d = 4; }

        if (!c) { maxDepth = depth; }
    }
    else
    {
        if (d <= 4) { d = 4; }
        else if (d <= 7) { d = 7; }
        else { d = 4; c = true; }
    }

    if (d != dOld) { maxDepth = depth; }

    ll ret = 10 * next(x / 10, depth + 1, c);
    return ret + (depth < maxDepth ? 4 : d);
}

int main()
{
    ll l, r;
    cin >> l >> r;

    ll sum{0};
    ll i{l};
    while (i <= r)
    {
        ll ni = next(i);
        sum += (min(r, ni) - i + 1) * ni;
        i = ni + 1;
    }

    cout << sum << endl;

    return 0;
}

