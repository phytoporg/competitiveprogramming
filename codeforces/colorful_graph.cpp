#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    static vector<int> colors(n);
    for (int i = 0; i < n; ++i) { cin >> colors[i]; }

    vector<pair<int, int>> edges(2*m + n);
    for (int i = 0; i < m; ++i)
    {
        int a; int b; cin >> a >> b;
        edges[2*i    ] = make_pair(colors[a-1], colors[b-1]);
        edges[2*i + 1] = make_pair(colors[b-1], colors[a-1]);
    }

    for (int i = 0; i < n; ++i)
    {
        edges[2*m + i] = make_pair(colors[i], colors[i]);
    }

    std::map<int, int> q;

    int maxk = -1;
    int maxq = -1;
    int k = 10e5+1;
    int c = 10e5+1;
    sort(begin(edges), end(edges), greater<pair<int, int>>());
    for(int i = 0; i < edges.size(); ++i)
    {
        auto [ki, ci] = edges[i];
        if (ki == k && ci < c)
        {
            q[k]++;
            c = ci;
        }
        else if(ki < k)
        {
            k = ki;
            c = ci;

            q[k] = 1;
        }

        if (maxq <= q[k]) { maxk = k; maxq = q[k]; }
    }

    cout << maxk;

    return 0;
}
