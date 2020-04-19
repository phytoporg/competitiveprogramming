#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)
using ull = unsigned long long;

int main()
{
    ull l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;

    bool found{false};
    for(ull cost = x; cost <= y; ++cost)
    {
        ull exp = cost * k;
        if (exp >= l && exp <= r) { found = true; break; }
    }

    cout << vector<string>{"NO", "YES"}[found] << endl;
}

