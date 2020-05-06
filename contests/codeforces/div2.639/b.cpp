#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    vector<ll> p_h(30000, 0);
    {
        int n(p_h.size());

        ll cards{0};
        for (int i = 1; i < n; ++i)
        {
            if (i == 1) { cards = 2; }
            else 
            {
                cards = cards + 3 * i - 1;
            }

            p_h[i] = cards;
        }
    }

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int count{0};

        for(;;)
        {
            auto it = lower_bound(begin(p_h), end(p_h), n);
            while (*it > n) { --it; }
            if (*it == 0) { break; }

            ++count;
            n -= *it;
        }

        cout << count << '\n';
    }

    return 0;
}

