#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int n; cin >> n;
        vector<ull> b(n);
        vector<ull> a(n);

        for (int i = 0; i < n; ++i)
        {
            ull ai, bi;
            cin >> ai >> bi;
            a[i] = ai; b[i] = bi;
        }

        ull bulletsUsed{0ll};
        ull mn(1e18);
        for (int i = 0; i < n; ++i)
        {
            int iNext{(i + 1) % n};
            ull score{min(a[iNext], b[i])};
            mn = min(score, mn);
            bulletsUsed += a[iNext] - score;
        }

        cout << bulletsUsed + mn << endl;
    }

    return 0;
}

