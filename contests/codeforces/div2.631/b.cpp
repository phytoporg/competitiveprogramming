#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        vector<int> range(n, a[0]);
        for (int i = 1; i < n; ++i) { range[i] = range[i - 1] + a[i]; }

        vector<vector<int>> solutions;
        for (int i = 0; i < n; ++i)
        {
            int lsum = (i + 1) * (i + 2) / 2;

            int k    = (n - i - 1);
            int rsum = k * (k + 1) / 2;
            if (range[i] == lsum && (range[n - 1] - range[i]) == rsum)
            {
                solutions.push_back({i + 1, n - i - 1});
            }
        }

        cout << solutions.size() << endl;
        for (auto& solution : solutions)
        {
            cout << solution.front() << ' ' << solution.back() << endl;
        }
    }

    return 0;
}
