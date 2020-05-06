#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;

        bool good{false};
        if (n == 1 || m == 1)
        {
            good = true;
        }
        else if (n == 2 && m == 2)
        {
            good = true;
        }

        cout << vector<string>{"NO\n", "YES\n"}[good];
    }

    return 0;
}
