#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> d;
    vector<int> vdegree(n + 1, 0);
    d.reserve(n + 1);

    for (int i = 0; i < n; ++i)
    {
        int ai; cin >> ai;
        int dn(d.size());
        if (dn < (ai + 1)) { d.resize(ai + 1); }
        d[ai].push_back(i + 1);
    }

    n = d.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
    {
        int mn{1};
        int count(d[i].size());
        if ((count < mn) || (i == 0 && count > 1))
        { 
            cout << "-1" << endl; return 0; 
        }

        if (i == 0) { continue; }

        int j = 0;
        int prevCount(d[i - 1].size());
        for (int l = 0; l < count; ++l, ++j)
        {
            int u = d[i - 1][j % prevCount];
            int v = d[i][l];

            vdegree[u]++;
            vdegree[v]++;
            if (vdegree[u] > k || vdegree[v] > k) 
            {
                cout << "-1" << endl; return 0;
            }

            ans.emplace_back(u, v);
        }
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
    {
        cout << u << ' ' << v << '\n';
    }

    return 0;
};

