#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
    ll w, b; cin >> w >> b;
    vector<vector<ld>> dp(w + 1, vector<ld>(b + 1));

    for (ll wi{0}; wi <= w; ++wi)
    {
        for (ll bi{0}; bi <= b; ++bi)
        {
            if (wi == 0 && bi == 0)
            {
                dp[0][0] = 0.0L;
            }
            else
            {
                ld p1 = 0.0L;
                if (bi >= 3)
                {
                   p1 = dp[wi][bi - 3] * (ld)(bi - 2) / (wi + bi - 2);
                }

                ld p2 = 0.0L;
                if (bi >= 2 && wi >= 1)
                {
                    p2 = dp[wi - 1][bi - 2] * (ld)(wi) / (wi + bi - 2);
                }

                ld p3 = 1.0L;
                if (bi > 1)
                {
                    p3 = ((ld)(bi - 1) / (wi + bi - 1)); 
                }

                dp[wi][bi] = 
                    (ld)wi / (wi + bi) +
                    ((ld)bi / (wi + bi)) * 
                    p3 * 
                    (p1 + p2);

            }
        }
    }

    cout << setprecision(9) << dp[w][b] << endl;

    return 0;
}

