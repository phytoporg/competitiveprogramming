#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;
    ll sum{0};
    for (int i = 0; i < n; ++i)
    {
        ll tmp; cin >> tmp;
        sum += tmp;
    }

    cout << (float)sum / n << endl;

    return 0;
}

