#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);

        using ptype = pair<int, int>;
        auto comp = [](ptype& x, ptype& y) {
                auto [xl, xr] = x;
                auto [yl, yr] = y;

                int xlen = xr - xl + 1;
                int ylen = yr - yl + 1;

                return xlen < ylen || (xlen == ylen && xl > yl);
            };
        priority_queue<ptype, vector<ptype>, decltype(comp)> pq(comp);

        int l = 0; int r = n - 1;
        int m = l + (r - l) / 2;
        a[m] = 1;

        for (int i = 0; i < n - 1; ++i) 
        {
            if ((m - l) > 0)     pq.emplace(l, m - 1);
            if ((r - m + 1) > 0) pq.emplace(m + 1, r);

            auto next = pq.top();
            pq.pop();

            l = next.first; r = next.second;
            m = l + (r - l) / 2;
            a[m] = i + 2;
        }

        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}

