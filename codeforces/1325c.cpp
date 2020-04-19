#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int n; cin >> n;

    vector<int> w(n, -1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; ++i)
    {
        int one, two;
        cin >> one >> two;
        adj[one].push_back(i);
        adj[two].push_back(i);
    }

    int nextWeight{0};
    for (auto& adjList : adj)
    {
        if (adjList.size() >= 3)
        {
            for (int iEdge : adjList)
            {
                if (w[iEdge] < 0) { w[iEdge] = nextWeight++; }
            }
        }
    }

    for (int iEdge = 1; iEdge < n; ++iEdge)
    {
        if (w[iEdge] < 0) { w[iEdge] = nextWeight++; }
        cout << w[iEdge] << "\n";
    }

    return 0;
}

