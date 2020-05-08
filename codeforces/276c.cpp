#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (auto& ai : a) { cin >> ai; }
    sort(begin(a), end(a));

    vector<ll> suffix(n, 0);
    while(q--)
    {
        int l, r; 
        cin >> l >> r;

        suffix[--r]++;

        if (l - 2 >= 0)
        {
            suffix[l - 2]--;
        }
    }

    vector<ll> counts(n, 0);
    counts.back() = suffix.back();
    for (int i = n - 2; i >= 0; --i)
    {
        counts[i] = counts[i + 1] + suffix[i];
    }

    sort(begin(counts), end(counts));
    ull sum{0};
    for (int i = 0; i < n; ++i)
    {
        sum += counts[i] * a[i];
    }

    cout << sum << endl;

    return 0;
}

