#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (auto& ai : a) { cin >> ai; }

    vector<ll> prefix(n, 1);
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] < a[i])
        {
            prefix[i] = prefix[i - 1] + 1;
        }
    }

    ll mx{1};
    vector<ll> suffix(n, 1);
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[i + 1] > a[i])
        {
            suffix[i] = suffix[i + 1] + 1;
            mx = max(mx, suffix[i]);
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (i > 0 && i < (n - 1) && a[i - 1] < a[i + 1])
        {
            mx = max(mx, prefix[i - 1] + suffix[i + 1]);
        }
    }

    cout << mx << endl;

    return 0;
}

