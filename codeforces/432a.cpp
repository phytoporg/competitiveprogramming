#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, k;
    cin >> n >> k;

    int eligible{0};
    for (int i = 0; i < n; ++i)
    {
        int contests; cin >> contests;
        eligible += ((contests + k) <= 5);
    }
    
    cout << eligible / 3 << endl;

    return 0;
};

