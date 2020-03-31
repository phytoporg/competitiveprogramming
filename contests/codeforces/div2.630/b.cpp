#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimes(int n)
{
    bitset<1000> isPrime(string(1000, '1'));
    for(int p = 2; p*p <= n; ++p)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i*i <= n; ++i)
    {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int main()
{
    vector<int> primes = getPrimes(1000);

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        int m{0};
        unordered_map<int, int> cmap;
        vector<int> c(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < primes.size(); ++j)
            {
                if (a[i] % primes[j] == 0) 
                {
                    if (!cmap.count(primes[j])) { cmap[primes[j]] = ++m; }
                    c[i] = cmap[primes[j]];
                    break;
                }
            }
        }

        cout << m << endl;
        for (int& ci : c) { cout << ci << " \n"[&ci == &c.back()]; }
    }
}

