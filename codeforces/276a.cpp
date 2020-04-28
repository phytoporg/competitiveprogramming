#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, k;    
    cin >> n >> k;

    int maxJoy{INT_MIN};
    while(n--)
    {
        int f, t;
        cin >> f >> t;

        if (t > k)
        {
            maxJoy = max(maxJoy, f - (t - k));
        }
        else
        {
            maxJoy = max(maxJoy, f);
        }
    }

    cout << maxJoy << endl;

    return 0;
}
