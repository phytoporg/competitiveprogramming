#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<bool> s(n, false);

        bool good{true};
        for(int i = 0; i < n; ++i) 
        {
            int ai;
            cin >> ai;
            int mod = (((ai + i) % n) + n) % n;
            if (good && !s[mod])
            {
                s[mod] = true;
            }
            else
            {
                good = false;
            }
        }

        cout << vector<string>{"NO\n", "YES\n"}[good];
    }

    return 0;
}

