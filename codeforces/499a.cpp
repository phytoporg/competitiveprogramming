#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<pair<ll,ll>> l(n);
    for (auto& p : l) 
    {
        ll a, b;
        cin >> a >> b; 
        p = make_pair(a, b);
    }

    sort(begin(l), end(l));

    //1 2 3 4 5 6 7 8 9 10 11 12

    ll current{1};
    ll minutes{0};
    for (ll i = 0; i < n; ++i)
    {
        auto [lb, le] = l[i];
        minutes += (lb - current) % x;
        minutes += (le - lb + 1);
        current = le + 1;
    }

    cout << minutes << endl;

    return 0;
};

