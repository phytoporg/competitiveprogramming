#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n; cin >> n;

    ll o_n{n / 2 + (n&1)};
    ll o_i{1};
    ll o_j{n - !(n&1)};
    ll e_n{n / 2};
    ll e_i{2};
    ll e_j{n - (n&1)};

    cout << (e_i + e_j) / 2LL * e_n - 
            (o_i + o_j) / 2LL * o_n;
         
    return 0;
}
