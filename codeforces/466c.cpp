#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    map<ll, ll> freq;

    int n; cin >> n;
    vector<int> a(n);
    for (int& ai : a) { cin >> ai; }

    vector<ll> p(n, a.front());
    for (int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }

    ll count{0};
    for (int i = 0; i < n - 1; ++i)
    {
        ll x = p[i] / 2;
        if (!(p[i] & 1) && p[i] + x == p.back())
        {
            count += freq[x];
        }

        if (!freq.count(p[i]))
        {
            freq.insert({p[i], 1});
        }
        else
        {
            freq[p[i]]++;
        }
    }

    cout << count << endl;

    return 0;
}

