#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    string s;
    cin >> s;

    for (char c : s)
    {
        if (c == 'H' || c == 'Q' || c == '9')
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}

