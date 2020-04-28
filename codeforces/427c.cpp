#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;

vector<bool> inStack(10e5 + 1, false);
vector<vector<int>> sccs;
void tarjan(
    int v,
    vector<vector<int>>& adjList,
    stack<int>& s,
    vector<int>& entry,
    vector<int>& low,
    int& time
    )
{
    time++;
    entry[v] = time;
    low[v]   = time;
    s.push(v);
    inStack[v] = true;

    for (auto& u : adjList[v])
    {
        if (entry[u] < 0)
        {
            tarjan(u, adjList, s, entry, low, time);
            low[v] = min(low[u], low[v]);
        }
        else if (inStack[u])
        {
            low[v] = min(low[u], entry[v]);
        }
    }

    if (low[v] == entry[v])
    {
        vector<int> scc;
        int u = -1;
        while(u != v)
        {
            u = s.top();
            s.pop();

            scc.push_back(u);
            inStack[u] = false;
        }

        sccs.push_back(scc);
    }
}

int main()
{
    int n; cin >> n;
    vector<ull> costs(n);
    for (int& ci : costs) { cin >> ci; }

    int m; cin >> m;
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }

    vector<int> entry(n, -1);
    vector<int> low(n);

    int time{0};
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        if (entry[i] < 0)
        {
            tarjan(i, adjList, s, entry, low, time);
            assert(s.empty());
        }
    }

    ull sumCost{0};
    long long numWays{1};
    for(auto& scc : sccs)
    {
        map<int, int> freq;

        ull mn(INT_MAX};
        int iMin{-1};
        int len(scc.size());
        for (int i = 0; i < len; ++i) 
        {
            int cost{costs[scc[i]]};
            if (cost < mn)
            {
                iMin = i;
                mn = cost;
            }

            if (!freq.count(cost)) { freq[cost] = 1; }
            else { freq[cost]++; }
        }

        sumCost += mn;

        static const int SecurityMod{1000000007};
        numWays = (freq[minCost] % SecurityMod) * 
                  (numWays % SecurityMod) % 
                  SecurityMod;
    }

    cout << sumCost << ' ' << numWays << endl;

    return 0;
}

