#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<ll> a(n);
        for (auto& ai : a) { cin >> ai; }

        bool sign{a.front() > 0};
        ll sum{0};
        ll mx = INT_MIN;
        for (auto ai : a) 
        {
            bool thisSign{ai > 0};
            if (sign != thisSign)
            {
                sign = thisSign;
                sum += mx;
                mx = INT_MIN;
            }

            mx = max(mx, ai);
        }

        sum += mx;
        cout << sum << endl;
    }

    return 0;
}

