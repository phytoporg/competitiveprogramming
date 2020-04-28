#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    ull n, l;
    cin >> n >> l;

    vector<ull> a(n);
    for (ull& ai : a) { cin >> ai; }
    sort(begin(a), end(a));

    ull left = a.front();
    ull right = l - a.back();
    ull maxDistance{0};
    for(ull i = 0; i < n - 1; ++i)
    {
        maxDistance = max(maxDistance, a[i + 1] - a[i]);
    }

    //
    // Proper solution here was to fall back on doubles but use
    // std::setprecision()
    //
    ull mx = max({left, right, maxDistance / 2});
    cout << mx;
    if (mx == (maxDistance / 2) && maxDistance & 1)
    {
        cout << ".5";
    }
    cout << endl;

    return 0;
}

