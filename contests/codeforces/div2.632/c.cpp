#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int n; cin >> n;

    vector<ll> a(n);
    for(ll& ai : a) { cin >> ai; }

    map<ll, int> freqs;
    vector<ll> sums(n);
    for (int i = 0; i < n; ++i)
    {
        if (i > 0) { sums[i] = sums[i - 1] + a[i]; }
        else { sums[i] = a[i]; }

        int si = sums[i];
        if (!freqs.count(si)) { freqs[si] = 1; }
        else { freqs[si]++; }
    }

    ll ideal = n * (n + 1) / 2;
    ll total = ideal;
    for (auto& [si, f] : freqs)
    {
        if (si == 0) total -= f;
        total -= (f - 1);
    }

    if (total != ideal && sums.back() != 0)
    {
        --total;
    }

    cout << total << endl;

    return 0;
}

