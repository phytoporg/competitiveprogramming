#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    if (a == b) {
        cout << "0 6 0";
        return 0;
    }

    auto [lo, hi] = make_pair(min(a, b), max(a, b));
    int diff{hi-lo};

    int r1,tie,r2;
    int mid = hi - (diff / 2);
    if (!(diff & 1))
    {
        tie = 1;
        r1 = mid - 1; r2 = 6 - mid;
    }
    else
    {
        tie = 0;
        r1 = lo + (diff/2); r2 = 6 - r1;
    }

    if (a > b) { swap(r1, r2); }
    cout << r1 << " " << tie << " " << r2;

    return 0;
}
