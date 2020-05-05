#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int n, m; cin >> n >> m;

    vector<set<int>> adj(m);
    vector<vector<int>> membership(n);
    vector<vector<int>> groups(m);

    for (int mi = 0; mi < m; ++mi)
    {
        int count; cin >> count;
        for (int ci = 0; ci < count; ++ci)
        {
            int x; cin >> x;
            membership[x - 1].push_back(mi);
            groups[mi].push_back(x - 1);
        }
    }

    for (int mi = 0; mi < m; ++mi)
    {
        for (int x : groups[mi])
        {
            for (int mi2 : membership[x])
            {
                if (mi != mi2) 
                {
                    adj[mi].insert(mi2); 
                    adj[mi2].insert(mi); 
                }
            }
        }
    }

    vector<bool> userVisited(n);
    vector<ll>   groupSum(m);
    vector<bool> groupVisited(m);
    vector<int>  answer(n, -1);
    for (int mi = 0; mi < m; ++mi)
    {
        ll sum{0};

        queue<int> q;
        if (!groupVisited[mi])
        {
            q.push(mi);
        }

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            groupVisited[v] = true;
            for (int x : groups[v])
            {
                if (!userVisited[x]) { ++sum; answer[x] = mi; }
                userVisited[x] = true;
            }

            for (int mi2 : adj[v])
            {
                if (!groupVisited[mi2]) { q.push(mi2); }
            }
        }

        groupSum[mi] = sum;
    }

    for (int ni = 0; ni < n; ++ni)
    {
        if (answer[ni] < 0) { cout << "1 "; }
        else { cout << groupSum[answer[ni]] << ' '; }
    }

    cout << endl;

    return 0;
}

