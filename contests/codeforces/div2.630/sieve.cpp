//
// Scratch
//

#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimes(int n)
{
    assert(n <= 1000);
    bitset<1000> prime(string(1000, '1'));

    for (int p = 2; p*p <= n; ++p)
    {
        if (prime[p])
        {
            for (int i = p*2; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (prime[i]) primes.push_back(i);
    }

    return primes;
}

int main()
{
    auto primes = getPrimes(1000);
    if (primes.empty()) { cout << "EMPTY" << endl; }
    for (int& p : primes)
    {
        cout << p << " \n"[&p == &primes.back()];
    }

    return 0;
}
