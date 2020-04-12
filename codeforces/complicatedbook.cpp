#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) { cin >> p[i]; }

    while(m--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        int numLess{0};
        for (int i = l; i <= r; ++i)
        {
            numLess += (i != x && p[i] < p[x]);
        }

        bool same = (x - l) == numLess;
        cout << vector<string>{"Yes", "No"}[!same] << "\n";
    }

    return 0;
};

