#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

template<int N>
struct Precompute
{
    constexpr Precompute() : values()
    {
        ll cards{0};
        for (int i = 1; i < N; ++i)
        {
            if (i == 1) { cards = 2; }
            else 
            {
                cards = cards + 3 * i - 1;
            }

            values[i] = cards;
        }
    }

    int values[N];
};

int main()
{
    Precompute<30000> precomp;
    auto& p_h = precomp.values;

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int count{0};

        for(;;)
        {
            auto it = lower_bound(begin(p_h), end(p_h), n);
            while (*it > n) { --it; }
            if (*it == 0) { break; }

            ++count;
            n -= *it;
        }

        cout << count << '\n';
    }

    return 0;
}

