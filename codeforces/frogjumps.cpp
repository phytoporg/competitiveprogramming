#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;

        s = 'R' + s + 'R';

        int last = 0;
        int mx{-1};
        int n(s.length());
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
            {
                if (i - last > mx) { mx = i - last; }
                last = i;
            }
        }

        cout << mx << endl;
    }

    return 0;
}

