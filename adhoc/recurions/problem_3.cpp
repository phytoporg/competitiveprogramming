#include <bits/stdc++.h>
using namespace std;

void removeOdds(vector<int>& a, int k, int& o)
{
    if (k == a.size()) return;

    if (o < 0)
    {
        a[k + o] = a[k];
    }

    o -= (a[k] & 1);
    removeOdds(a, k + 1, o);
}

int main() 
{
    int n; cin >> n;

    std::vector<int> v(n);
    int i{0};
    while(cin >> v[i++]);

    int k = 0;
    int o = 0;
    removeOdds(v, k, o);
    cout << o << endl;

    for (int i = 0; i < (v.size() + o); ++i)
    {
        cout << v[i] << " ";
    }

    return 0;
}
