#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        ll maxA{-1};
        vector<ll> a(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
            maxA = max(a[j], maxA);
        }

        if (k == 1) { cout << "YES" << endl; continue; }

        int maxi{0};
        ll maxVal{1};
        while(maxVal < maxA)
        {
            maxVal *= k;
            ++maxi;
        }

        bitset<100> used;
        bool good{true};
        for (int j = 0; j < n && good; ++j)
        {
            ll tmpVal{maxVal};
            int i{maxi};
            while(good && a[j])
            {
                while(tmpVal > a[j])
                {
                    --i;
                    tmpVal /= k;
                }

                if (used[i]) 
                {
                    good = false;
                    break;
                }

                a[j] -= tmpVal;
                used[i] = true;
            }
        }

        cout << vector<string>{"NO", "YES"}[good] << endl;
    }

    return 0;
}
