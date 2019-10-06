#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> edges(n);
    vector<bool> visited(n, false);
    {
        int i{0};
        while(cin >> edges[i++]);
    }

    for(size_t i = 0; i < n; ++i)
    {
        int ai = i;
        while(!visited[ai])
        {
            visited[ai] = true;
            ai = edges[ai] - 1;
        }
        cout << ai + 1 << " ";
        visited = vector<bool>(n, false);
    }

    return 0;
}
