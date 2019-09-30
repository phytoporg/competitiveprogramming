#include <bits/stdc++.h>
using namespace std;

void doReverseHelper(const vector<int>& v, vector<int>& r, int k)
{
    if (k == v.size())
    {
        return;
    }

    doReverseHelper(v, r, k + 1);
    r.emplace_back(v[k]);
}

vector<int> doReverse(const vector<int>& v)
{
    vector<int> reversed;
    doReverseHelper(v, reversed, 0);
    return reversed;
}

int main()
{
    int n; cin >> n;
    vector<int> v(n);

    int i = 0;
    while(cin >> v[i++]);

    auto r = doReverse(v);
    for (auto i : r) cout << i << " ";

    return 0;
}
