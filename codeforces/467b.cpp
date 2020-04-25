#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> players(m + 1);
    for (int& pi : players) { cin >> pi; }

    int fedor{players.back()};
    int friends{0};
    for (int i = 0; i < m; ++i)
    {
        if (__builtin_popcount(fedor ^ players[i]) <= k) ++friends;
    }

    cout << friends << endl;

    return 0;
};

