#include <bits/stdc++.h>
using namespace std;

#define OUTVAR(x) (cout << #x << " is " << x << endl)

const int MAX_W = 30;
bitset<MAX_W> can;
int main()
{
    int n, W;
    cin >> n >> W;
    can[0] = true;
    for (int id = 0; id < n; ++id)
    {
        int x;
        cin >> x;
        for(int i = W; i >= x; --i)
        {
            if(can[i-x]) can[i] = true;
        }
        OUTVAR(x);
        OUTVAR(can);
    }

    cout << (can[W] ? "YES" : "NO" ) << endl;

    return 0;
}

