#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> cn(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        int e; cin >> e;
        if (find(begin(adj[i]), end(adj[i]), e) == end(adj[i]))
        {
            adj[i].push_back(e);
        }

        if (find(begin(adj[e]), end(adj[e]), i) == end(adj[e]))
        {
            adj[e].push_back(i);
        }
    }

    int count{0};
    for (int i = 1; i <= n; ++i)
    {
        if (cn[i] == 0)
        {
            ++count;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int current = q.front();
                q.pop();

                if (cn[current] == 0)
                {
                    cn[current] = count;
                    for (int& a : adj[current])
                    {
                        if (cn[a] == 0) { q.push(a); }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
};

