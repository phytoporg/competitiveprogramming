#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; int m;
    cin >> n >> m;

    ll preva{1};
    ll a;
    ull time{0};
    while(m--)
    {
        cin >> a;
        if (a > preva)
        {
            time += (a - preva);
        }
        else if (a < preva)
        {
            time += n + (a - preva);
        }

        preva = a;
    }

    cout << time << endl;

    return 0;
}

