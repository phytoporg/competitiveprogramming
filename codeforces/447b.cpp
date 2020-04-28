#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    string s; ll k;
    cin >> s >> k;

    ll mx{-1};
    ll w[26];
    for (int i = 0; i < 26; ++i)
    {
        cin >> w[i];
        mx = max(mx, w[i]);
    }

    ll score{0};
    int n(s.size());
    for (int i = 1; i <= n; ++i)
    {
        score += w[s[i - 1] - 'a'] * i;
    }

    for (int i = n + 1; i <= n + k; ++i)
    {
        score += mx * i;
    }

    cout << score << endl;

    return 0;
}

