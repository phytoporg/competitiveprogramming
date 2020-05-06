#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int& ai : a) { cin >> ai; }

        vector<int> peaks(n, 0);
        int peakcount{0};
        int maxpeaks{0};
        int imax{0};
        for(int i = 1; i < n; ++i)
        {
            peaks[i] = peakcount;

            int idx{max(0, i - k + 1)};
            int diff{peaks[i] - peaks[idx]};
            if (diff > maxpeaks)
            {
                maxpeaks = diff;
                imax = idx;
            }

            if ((i < n - 1) && a[i - 1] < a[i] && a[i] > a[i + 1])
            {
                ++peakcount;
            }
        }

        cout << maxpeaks + 1 << ' ' << imax + 1  << '\n';
    }

    return 0;
}

