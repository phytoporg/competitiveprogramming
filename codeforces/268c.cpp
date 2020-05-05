#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int n, m; cin >> n >> m;

    int ans{min(n, m)};
    cout << ans + 1 << endl;

    int x{n};
    int y{0};
    for(int i = 0; i < ans + 1; ++i)
    {
        cout << x-- << ' ' << y++ << '\n';
    }

    return 0;
}

