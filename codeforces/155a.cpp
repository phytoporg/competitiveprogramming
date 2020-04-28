#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int n; cin >> n;

    int amazing{0};
    int mn{INT_MAX}, mx{INT_MIN};
    for (int i = 0; i < n; ++i)
    {
        int ai; cin >> ai;
        if (i == 0)
        {
            mn = min(mn, ai);
            mx = max(mx, ai);
        }
        else if (ai < mn)
        {
            ++amazing;
            mn = ai;
        }
        else if (ai > mx)
        {
            ++amazing;
            mx = ai;
        }
    }

    cout << amazing << endl;

    return 0;
}

