#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    ull m, n; cin >> m >> n;

    auto choose2 = [](ull a) { return (a) * (a - 1) / 2; };

    ull q{m / n};
    ull r{m % n};
    ull kmin = choose2(q + 1) * r + choose2(q) * (n - r);
    ull kmax = choose2(m - n + 1);

    cout << kmin << ' ' << kmax << endl;

    return 0;
};

