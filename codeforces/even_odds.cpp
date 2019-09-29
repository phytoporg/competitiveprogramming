#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; ll m; cin >> n; cin >> m;

    ll numOdd{n / 2 + (n & 1)};
    ll numEven{n / 2};

    if(m <= numOdd)
    {
        cout << 1 + 2 * (m - 1);
    }
    else
    {
        cout << 2 * (m - numOdd);
    }

    return 0;
}

1 3 5 7 2 4 6
