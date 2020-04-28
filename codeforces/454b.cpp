#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;    
    vector<ll> a(n);
    for (auto& ai : a) { cin >> ai; }

    int shiftIndex{-1};
    for (int i = 0; i < n - 1; ++i)
    {
        ll diff{a[i] - a[i + 1]};
        if (shiftIndex < 0 && diff > 0)
        {
            shiftIndex = i + 1;
            break;
        }
    }

    for (int i = shiftIndex; i < (shiftIndex + n - 1) && shiftIndex > 0; ++i)
    {
        ll mod = i % n;
        ll next = (i + 1) % n;

        ll diff{a[mod] - a[next]};
        if (diff > 0) 
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    if (shiftIndex < 0) { cout << 0 << endl; }
    else { cout << n - shiftIndex << endl; }

    return 0;
}

