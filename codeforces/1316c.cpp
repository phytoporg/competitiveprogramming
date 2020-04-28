#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;

    int p_ai{-1};
    for(int i = 0; i < n; ++i)
    {
        int ai; cin >> ai;
        if (p_ai < 0 && ai % p != 0)
        {
            p_ai = i;
        }
    }

    int p_bi{-1};
    for(int i = 0; i < m; ++i)
    {
        int bi; cin >> bi;
        if (p_bi < 0 && bi % p != 0)
        {
            p_bi = i;
        }
    }

    cout << p_ai + p_bi << endl;

    return 0;
};

