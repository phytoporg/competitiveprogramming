#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int q; cin >> q;

    while(q--)
    {
        int n; int t; cin >> n >> t;
        bool good{true};

        ll ct_h{t}; int ct_l{t};
        ll T{0};
        while(n--)
        {
            ll Tnext, tnext_h, tnext_l;
            cin >> Tnext >> tnext_l >> tnext_h;

            ll dt = Tnext - T;
            ll maxt = ct_h + dt;
            ll mint = ct_l - dt;

            if (tnext_h < mint || tnext_l > maxt)
            {
                good = false;
            }

            ct_h = min(maxt, tnext_h);
            ct_l = max(mint, tnext_l);
            T = Tnext;
        }

        cout << vector<string>{ "NO\n", "YES\n" }[good];
    }

    return 0;
}

