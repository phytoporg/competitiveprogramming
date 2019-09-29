#include <bits/stdc++.h>
using namespace std;

void secondMax(const vector<int>& v, int& i, int& j, int k)
{
    if (k == v.size()) { return; }

    i = v[k] > v[i] ? k : i;
    secondMax(v, i, j, k + 1);
    j = v[i] > v[k] && v[k] >= v[j] ? k : j;
}

int main()
{
    int n; cin >> n;

    vector<int> v(n);
    {
        int i{0};
        while(cin >> v[i++]);
    }

    int k{0};
    int i{0};
    int j{0};
    secondMax(v, i, j, k);

    cout << v[j];

    return 0;
}
