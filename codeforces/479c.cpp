#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

using p = pair<int, int>;

int main()
{
    int n; cin >> n;
    vector<p> pairs(n);
    map<int, int> mins;
    map<int, int> maxs;
    for (int i = 0; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        if (mins.count(u)) { mins[u] = min(mins[u], v); }
        else { mins.insert({u, v}); }

        if (maxs.count(u)) { maxs[u] = max(maxs[u], v); }
        else { maxs.insert({u, v}); }
    }

    int ans{0};
    for (auto [u, v] : mins)
    {
        if (ans > v)
        {
            ans = u;
        }
        else
        {
            ans = maxs[u];
        }
    }

    cout << ans << endl;

    return 0;
}
