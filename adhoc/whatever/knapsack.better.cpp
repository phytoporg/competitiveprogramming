//
// Tips by Errichto:
// https://www.youtube.com/watch?v=jqJ5s077OKo
//

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

        //
        // This works because set bit positions signal the existence of a sum,
        // for the value corresponding to that bit index.
        //
        // e.g. 1 is already set and we're considering incoming value 5. 6 is 
        // therefore a possible sum, which amounts to shifting 1 by 5 to set
        // position 6.
        //
        can |= (can << x);

        OUTVAR(x);
        OUTVAR(can);
    }

    cout << (can[W] ? "YES" : "NO" ) << endl;

    return 0;
}

