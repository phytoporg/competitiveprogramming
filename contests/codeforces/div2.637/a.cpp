#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int gmin{a - b};
        int gmax{a + b};
        int pmin{c - d};
        int pmax{c + d};

        bool cant{(n * gmin > pmax) || (n * gmax < pmin)};

        cout << vector<string>{"No", "Yes"}[!cant] << '\n';
    }

    return 0;
}
