#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, m; cin >> n >> m;

    if (n > (m + 1) || m > 2 * (n + 1))
    {
        cout << "-1";
    }
    else
    {
        if (n > m)
        {
            cout << "0"; --n;
        }

        while (m > n && n > 0)
        {
            cout << "110"; m -= 2; --n;
        }

        while (m > n && n == 0)
        {
            cout << "1"; --m;
        }

        while (m == n && m > 0)
        {
            cout << "10"; --m; --n;
        }
    }

    cout << endl;

    return 0;
};
