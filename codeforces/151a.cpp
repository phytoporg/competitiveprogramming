#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drinks = (k * l) / (nl * n);
    int slices = (c * d) / n;
    int salt = p / (np * n);

    cout << min({drinks, slices, salt}) << endl;

    return 0;
};
