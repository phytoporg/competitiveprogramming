#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;

int main()
{
    ull MAX_N{2500001};
    vector<ull> dp(MAX_N);

    dp[3] = 8;
    for (ull i = 5; i < MAX_N - 1; i += 2)
    {
        dp[i] = dp[i - 2] + (i * 4 - 4) * (i / 2);
    }

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}

