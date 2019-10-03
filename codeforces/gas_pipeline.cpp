#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        string s; cin >> s;

        auto inf = static_cast<ll>(1e18);
        vector<array<ll, 2>> d(n + 1, {inf, inf});
        d[0][0] = b;
        for(size_t i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                d[i+1][0] = min(d[i][0] + a + b,     d[i][1] + 2*a + b);
                d[i+1][1] = min(d[i][0] + 2*(a + b), d[i][1] + a + 2*b);
            }
            else
            {
                d[i+1][1] = min(d[i+1][1], d[i][1] + a + 2*b);
            }
        }

        cout << d[n][0] << endl;
    }


    return 0;
}
