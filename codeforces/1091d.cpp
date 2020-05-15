#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;
ull MOD = 998244353;

int main()
{
    vector<ull> fact(10e6 + 1);
    fact[0] = 1;
    for (size_t i = 1; i < fact.size(); ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ull> dp(10e6 + 1);
    dp[1] = 1;
    for (size_t i = 2; i < dp.size(); ++i)
    {
        dp[i] = (((dp[i - 1] + fact[i - 1] - 1) % MOD) * i) % MOD;
    }

    ull n; cin >> n;    
    cout << dp[n] << endl;

    return 0;
}

