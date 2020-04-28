#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int pi; cin >> pi;
        p[pi] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << p[i] << ' ';
    }

    return 0;
}

