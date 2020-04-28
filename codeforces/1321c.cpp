#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; string s;
    cin >> n >> s;

    int total{n};
    while(n)
    {
        char mx{'a' - 1};
        int iMax{-1};
        for (int i = 0; i < n; ++i)
        {
            if (s[i] > mx && 
                (((i > 0)    && (s[i - 1]  == s[i] - 1)) ||
                ((i < n - 1) && (s[i + 1] == s[i] - 1))))
            {
                iMax = i;
                mx = s[i];
            }
        }

        if (iMax < 0) { break; }
        s.erase(begin(s) + iMax);
        n--;
    }

    cout << total - n << endl;

    return 0;
};
