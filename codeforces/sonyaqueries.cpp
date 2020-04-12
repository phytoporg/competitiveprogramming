#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull convert(ull x)
{
    ull ret{0};
    for (int i{0}; x > 0; ++i)
    {
        int digit = x % 10;
        ret |= (digit & 1) << i;
        x /= 10;
    }

    return ret;
}

int main()
{
    int t; cin >> t;
    map<ull, ull> lut;
    while(t--)
    {
        char q; ull x;

        cin >> q >> x;
        ull converted = convert(x);
        if (q == '+')
        {
            if (lut.count(converted)) { lut[converted]++; }
            else { lut[converted] = 1; }
        }
        else if (q == '-')
        {
            lut[converted]--;
        }
        else if (q == '?')
        {
            cout << lut[converted] << "\n";
        }
    }

    return 0;
};

