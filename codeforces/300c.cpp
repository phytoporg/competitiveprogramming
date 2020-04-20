#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

const ull Mod(1000000007);

//
// See wikipedia entry for modular exponentiation.
//
// The exponent is expressed as a sum of powers of two, so then b^e is
// b^(Sum_i{a_i * 2^i}) where a_i is either 0 or 1 for each term.
//
// This turns into a product of b raised to each 2^i, raised again by
// a_i.
//
ull powMod(ull base, ull exp, ull mod)
{
    ull result = 1;
    base %= mod;

    while(exp)
    {
        if (exp & 1)
        {
            result = (result * base) % mod;
        }

        exp >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    vector<ull> fact(10e6 + 1, 1);
    int maxN(fact.size());
    for (int i = 1; i < maxN; ++i) { fact[i] = (fact[i - 1] * i) % Mod; }

    int a, b, n;
    cin >> a >> b >> n;

    ull sum{0};
    for(int i = 0; i <= n; ++i)
    {
        int val{a * i + b * (n - i)};
        bool excellent{true};
        while(val)
        {
            int digit{val % 10};
            if (digit != a && digit != b)
            {
                excellent = false;
                break;
            }

            val /= 10;
        }

        if (excellent)
        {
            //
            // Fermat's little theorem: for prime p,
            // - a^p = a mod p
            // - a^(p - 1) = 1 mod p
            // 
            // So, inv(a) mod p = a^(p - 2) mod p because
            // a * a^(p - 2) mod p = a^(p - 1) mod p = 1 mod p
            //
            // Really neat!
            //
            sum += fact[n] * powMod(fact[i] * fact[n - i], Mod - 2, Mod);
            sum %= Mod;
        }
    }

    cout << sum << endl;
    
    return 0;
};

