#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> v(m);
    {
        int i{0};
        while(cin >> v[i++]);
    }

    sort(begin(v), end(v));
    int i{0};
    int j{n - 1};

    int minDistance{numeric_limits<int>::max()};
    while(j < v.size())
    {
        minDistance = min(minDistance, v[j] - v[i]);
        ++i; ++j;
    }

    cout << minDistance;

    return 0;
}
