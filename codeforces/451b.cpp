#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int& ai : a) { cin >> ai; }

    vector<pair<int, int>> ans;

    int istart{-1};
    int iend{-1};
    for (int i = 0; i < n - 1; ++i)
    {
        ll diff{a[i + 1] - a[i]};
        if (istart < 0 && diff < 0)
        {
            istart = i;
        }

        if ((istart >= 0 && diff > 0) || 
            (istart >= 0 && i == (n - 2) && diff < 0))
        {
            iend = (diff > 0) ? i : i + 1;

            if (ans.empty() && 
                    (istart == 0 || a[iend] > (a[istart - 1])) &&
                    (iend == (n - 1) || a[istart] < a[iend + 1]))
            {
                ans.emplace_back(istart + 1, iend + 1);
                istart = -1;
            }
            else
            {
                cout << "no" << endl; return 0;
            }
        }
    }

    if (!ans.empty())
    {
        auto& [b, e] = ans.front();
        cout << "yes\n" << b << ' ' << e << endl;
    }
    else
    {
        cout << "yes\n1 1" << endl;
    }

    return 0;
}

