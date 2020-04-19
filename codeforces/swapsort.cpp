#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int& ai : a) { cin >> ai; }

    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; ++i)
    {
        int min = a[i];
        int iMin = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < min) { min = a[j]; iMin = j; }
        }

        if (i != iMin)
        {
            swaps.emplace_back(i, iMin);
            swap(a[iMin], a[i]);
        }
    }

    cout << swaps.size() << '\n';
    for (auto& [i, j] : swaps)
    {
        cout << i << ' ' << j << ' ' << endl;
    }

    return 0;
};
