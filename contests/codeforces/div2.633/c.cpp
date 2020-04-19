#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int highestBit(ll n)
{
    int highest{0};
    for (int i = 63; i >= 0; --i)
    {
        if (n & (1ll << i)) { highest = i; break; }
    }

    return highest + 1;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        int i{0};
        int maxT{0};
        while(i < n)
        {
            while (i < n - 1 && a[i] <= a[i + 1]) { ++i; }
            //if (a[i] <= a[i + 1]) { break; }
            if (i == n - 1) { break; }

            int j = i + 1;
            int iMin{-1};
            int minVal{INT_MAX};
            while (j < n && a[i] > a[j]) 
            {
                if (a[j] < minVal) { iMin = j; minVal = a[j]; }
                ++j; 
            }
            
            if (iMin >= 0)
            {
                ll diff = a[i] - a[iMin];
                maxT = max(maxT, highestBit(diff));
            }

            i = j;
        }

        cout << maxT << endl;
    }

    return 0;
}
