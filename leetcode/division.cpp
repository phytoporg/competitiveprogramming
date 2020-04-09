#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int divide(int dividend, int divisor) 
{
    if (dividend == 0) { return 0; }

    bool sign = (dividend < 0 && divisor < 0) ||
                (dividend > 0 && divisor > 0);

    ll dd = dividend;
    ll dr = divisor;

    dd = abs(dd); dr = abs(dr);
    ll temp{0ll}; ll q{0ll};
    for (int i = 31; i >= 0; --i)
    {
        if ((temp + (dr << i)) <= dd)
        {
            temp += dr << i;
            q |= 1ll << i;
        }
    }
    
    if (!sign) { q = -q; }
    if (q < INT_MIN || q > INT_MAX) { return INT_MAX; }

    return static_cast<int>(q);
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    cout << divide(n1, n2) << endl;
    
    return 0;
}
