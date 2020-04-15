#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (ll& ai : a) { cin >> ai; }

        bool good{true};
        if (k > 1)
        {
            int i = 0;
            ll maxK{1};
            while (maxK <= 10e16)
            {
                maxK *= k;
                ++i;
            }

            int updates{0};
            ll iMax{-1};
            ll mx{-1};
            for (int j = 0; j < n; ++j)
            {

            }
        }

        cout << vector<string>{"NO","YES"}[good] << endl;
    }

    return 0;
}

