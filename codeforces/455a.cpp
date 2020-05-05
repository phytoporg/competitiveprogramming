#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)
using ll = long long;

int N{1000010};
int main()
{
    ll n; cin >> n;

    map<ll, ll> freq;
    for (int i = 0; i < n; ++i)
    {
        int ai; cin >> ai;
        if (!freq.count(ai)) { freq.insert({ai, 1}); }
        else { freq[ai]++; }
    }

    vector<ll> dp(N);
    dp[0] = 0;
    dp[1] = freq[1];
    for (ll i = 2; i < N; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
    }

    cout << dp[N - 1] << endl;

    return 0;
}

