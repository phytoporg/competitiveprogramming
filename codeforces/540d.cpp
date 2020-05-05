#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ld = long double;

ld dp[101][101][101];
int main()
{
    int r, s, p; cin >> r >> s >> p;

    ld probR{0.0L};
    ld probS{0.0L};
    ld probP{0.0L};

    dp[r][s][p] = 1.0L;
    for (int ri = r; ri >= 0; --ri)
    {
        for (int si = s; si >= 0; --si)
        {
            for (int pi = p; pi >= 0; --pi)
            {
                int rp = ri * pi;
                int rs = ri * si;
                int ps = pi * si;
                int total{rp + rs + ps};

                if (total)
                {
                    if (ri)
                    {
                        dp[ri - 1][si][pi] += dp[ri][si][pi] * (ld)rp / total;
                    }

                    if (si)
                    {
                        dp[ri][si - 1][pi] += dp[ri][si][pi] * (ld)rs / total;
                    }

                    if (pi)
                    {
                        dp[ri][si][pi - 1] += dp[ri][si][pi] * (ld)ps / total;
                    }
                }

                if (ri && !si && !pi)
                {
                    probR += dp[ri][si][pi];
                } 
                else if (si && !ri && !pi)
                {
                    probS += dp[ri][si][pi];
                } 
                else if (pi && !si && !ri)
                {
                    probP += dp[ri][si][pi];
                }
            }
        }
    }

    cout << setprecision(9) << probR << ' ' << probS << ' ' << probP << endl;

    return 0;
}

