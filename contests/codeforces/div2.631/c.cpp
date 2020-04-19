#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i) 
    {
        cin >> a[i]; 
        if (a[i] + i - 1 > n)
        {
            cout << "-1\n";
            return 0;
        }
    }

    vector<ll> sums(m + 1);
    sums.back() = a.back();
    for (int i = m - 1; i > 0; --i)
    {
        sums[i] = a[i] + sums[i + 1];
    }

    if (sums[1] < n) { cout << "-1\n"; return 0; }

    for (int i = 1; i <= m; ++i)
    {
        int pi = max(ll(i), n - sums[i] + 1);
        cout << pi << " \n"[i == m];
    }
    
    return 0;
}

