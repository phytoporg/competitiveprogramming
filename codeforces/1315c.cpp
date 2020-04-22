#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> b(n);
        vector<bool> seen(n * 2, false);
        for(int& bi : b) { cin >> bi; seen[bi - 1] = true; }

        vector<int> a;
        for (int i = 0; i < (2 * n); ++i)
        {
            if (!seen[i]) { a.push_back(i + 1); }
        }

        vector<int> ans(n);
        bool good{true};
        for (int i = 0; i < n; ++i)
        {
            int mn{2000};
            int imn{-1};
            for (int j = 0; j < n; ++j)
            {
                if (!seen[a[j] - 1] && a[j] > b[i] && a[j] < mn) 
                {
                    imn = j; mn = a[j]; 
                }
            }

            if (imn < 0)
            {
                cout << "-1" << endl;
                good = false;
                break;
            }

            seen[mn - 1] = true;
            ans[i] = mn;
        }

        if (!good) { continue; }

        for(int i = 0; i < n; ++i)
        {
            cout << b[i] << ' ' << ans[i] << ' ';
        }
        cout <<endl;
    }

    return 0;
}

