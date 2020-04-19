//
// Permutation partitions
//
#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;

int main()
{
    int n; int k;
    cin >> n >> k;

    vector<int> p(n);
    for(int& pi : p) { cin >> pi; }

    int last{-1};
    ull product{1};
    ull partitionValue{0};
    for (int i = 0; i < n; ++i)
    {
        if (p[i] > n - k)
        {
            partitionValue += p[i];
            if (last >= 0 && i - last > 0)
            {
                product *= ((i - last) % 998244353);
                product %= 998244353;
            }

            last = i;    
        }
    }

    cout << partitionValue << ' ' << product << endl;

    return 0;
}

