#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    ll b[3];
    cin >> b[0] >> b[1] >> b[2];
    sort(b, b + 3);

    if (2 * (b[0] + b[1]) <= b[2])
    {
        cout << b[0] + b[1] << endl;
    }
    else
    {
        cout << (b[0] + b[1] + b[2]) / 3 << endl;
    }

    return 0;
}

