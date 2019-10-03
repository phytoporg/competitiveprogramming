#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    bitset<10000> prime;
    prime.set();

    if (n == 1)   return false;
    if (n == 2)   return true;
    if (!(n & 1)) return false;

    for(int i = 3; i*i <= n; i += 2)
    {
        if (prime[i])
        {
            for(int j = i*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    return prime[n];
}

int main()
{
    int n; cin >> n;
    cout << (isPrime(n) ? "YES" : "NO") << endl;

    return 0;
}
