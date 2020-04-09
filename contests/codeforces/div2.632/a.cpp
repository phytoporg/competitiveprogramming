#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        int m; cin >> m;

        int b{0}; int w{0};
        for (int i = 0; i < n; ++i)
        {
            int jStart{0};
            if (b == w)
            {
                if (!(m & 1)) { jStart = 1; cout << 'B'; }
            }
            else
            {
                if (m & 1) { jStart = 1; cout << 'B'; }
            }

            char chars[] = {'B', 'W'};
            int c = 0;
            for (int j = jStart; j < m; ++j)
            {
                if (!c) { ++b; } else { ++w; }

                cout << chars[c++];
                c &= 1;
            }
            cout << '\n';
        }
    }

    return 0;
}

