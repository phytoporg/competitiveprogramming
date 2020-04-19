#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

void dfs(
    int node,
    vector<vector<ll>>& adjList,
    vector<ll>& children,
    vector<ll>& depths,
    set<ll>& seen,
    ll& nodeCount,
    ll depth)
{
    seen.insert(node);

    ll initialNodeCount{nodeCount};
    depths[node] = depth;

    ll childrenSum{0};
    for (auto& toVisit : adjList[node])
    {
        if (!seen.count(toVisit))
        {
            dfs(toVisit, adjList, children, depths, seen, nodeCount, depth + 1);
            childrenSum += (nodeCount - initialNodeCount);
            initialNodeCount = nodeCount;
        }
    }

    ++nodeCount;
    children[node] = childrenSum;
}

int main()
{
    int n; int k;
    cin >> n >> k;

    vector<vector<ll>> adjList(n + 1);
    vector<ll> children(n + 1, -1);
    vector<ll> depths(n + 1, 0);
    set<ll> seen;

    for(int e = 1; e < n; ++e)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    ll nodeCount{0};
    ll depth{0};
    dfs(1, adjList, children, depths, seen, nodeCount, depth);

    vector<int> range(n + 1);
    iota(begin(range), end(range), 0);

    sort(begin(range) + 1, end(range),
        [&children, &depths](ll a, ll b)
        {
            return (depths[a] - children[a]) > (depths[b] - children[b]);
        });

    ll sumHappiness{0};
    for (int i = 1; i <= k; ++i)
    {
        sumHappiness += depths[range[i]] - children[range[i]];
    }

    cout << sumHappiness << endl;

    return 0;
}

