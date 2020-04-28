#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    string s;
    for (int i = 0; i < 8; ++i)
    {
        cin >> s;
        for (int c = 0; c < 7; ++c)
        {
            if (s[c] == s[c + 1])
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}

