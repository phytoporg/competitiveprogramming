#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
    ll n; cin >> n;
    ll groups{1};

    string s;
    string prevS;

    while(cin >> s)
    {
        if (!prevS.empty())
        {
            if (s != prevS) { ++groups; }
        }
        prevS = s;
    }

    cout << groups;

    return 0;
}
