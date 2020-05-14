#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;

        ll ans;
        if (n == 1)
        {
            ans = 0;
        }
        else if (n == 2)
        {
            ans = m;
        }
        else if (n > 2)
        {
            ans = 2 * m;
        }

        cout << ans << endl;
    }
    return 0;
}

