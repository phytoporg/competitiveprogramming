#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

vector<bool> isPrime(10000003, true);

int main()
{
    ll size(isPrime.size());

    for (int i = 2; i*i < size; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < size; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    unordered_set<ll> tprimes;
    for (ll i = 2; i < size; ++i)
    {
        if (isPrime[i]) tprimes.insert(i*i);
    }

    ll n; cin >> n;
    while(n--)
    {
        ll x; cin >> x;
        cout << vector<string>{ "NO", "YES" }[tprimes.count(x)] << endl;;
    }

    return 0;
};
