#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

ll query(ll l, int ab, const vector<int> p)
{
    ll range{l / ab};
    ll rem{l % ab};

    return p.back() * range + p[rem] * 1LL;
}

int main()
{
    int T; cin >> T;    
    while(T--)
    {
        int a, b, q; cin >> a >> b >> q;

        int ab = a * b;
        vector<int> prefix(ab + 1);
        for(int i = 1; i <= ab; ++i)
        {
            prefix[i] = prefix[i - 1];
            if ((i % a) % b != (i % b) % a)
            {
                prefix[i]++;
            }
        }

        while(q--)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(r, ab, prefix) - query(l - 1, ab, prefix) << endl;
        }
    }

    return 0;
}

