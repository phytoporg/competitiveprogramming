#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        vector<int> b(n);
        for (int& bi : b) { cin >> bi; }

        int lt{-1};
        int gt{-1};
        bool good{true};
        for (int i = 0; i < n; ++i)
        {
            if ((b[i] > a[i] && gt < 0) || (b[i] < a[i] && lt < 0)) 
            { 
                good = false; break;
            }

            if (lt < 0 && a[i] < 0) { lt = i; }
            if (gt < 0 && a[i] > 0) { gt = i; }
            if (lt >= 0 && gt >= 0) { break; }
        }

        cout << vector<string>{"NO\n", "YES\n"}[good];
    }

    return 0;
}
