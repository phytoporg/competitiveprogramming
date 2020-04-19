#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;

    while(n--)
    {
        string s; cin >> s;
        if (s.length() > 10)
        {
            int newLen = s.length() - 2;
            stringstream ss;
            ss << s[0] << newLen << s.back();

            cout << ss.str() << "\n";
        }
        else
        {
            cout << s << "\n";
        }
    }

    return 0;
};

