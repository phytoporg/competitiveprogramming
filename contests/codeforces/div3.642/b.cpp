#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (auto& ai : a) { cin >> ai; }

        vector<int> b(n);
        for (auto& bi : b) { cin >> bi; }

        partial_sort(begin(b), begin(b) + k, end(b), greater<int>());
        sort(begin(a), end(a));

        ll sum{0};
        for (int i = 0; i < n; ++i)
        {
            if (i < k)
            {
                sum += max(a[i], b[i]);
            }
            else
            {
                sum += a[i];
            }
        }

        cout << sum << endl;
    }

    return 0;
}

