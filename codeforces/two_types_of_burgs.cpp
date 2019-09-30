#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;

        int counts[] = { h >= c ? p : f, h <= c ? p : f };
        int prices[] = { max(h, c), min(h, c) };

        int nb = b / 2;
        int ne = min(nb, counts[0]);
        int nc = 0;
        if (nb - ne > 0)
        {
            nc = min(nb - ne, counts[1]);
        }

        cout << ne * prices[0] + nc * prices[1] << " \n"[i < (t - 1)];
    }
}
