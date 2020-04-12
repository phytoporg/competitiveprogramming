#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ll = long long;

int main()
{
    int n; cin >> n;

    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        int ai; cin >> ai; 
        prefix[i + 1] = prefix[i] + ai;
    }

    set<ll> s = {0};
    int i{0}; int j{0};
    ll answer{0};
    while(i < n)
    {
        while(j < n && !s.count(prefix[j + 1]))
        {
            ++j;
            s.insert(prefix[j]);
        }
        answer += j - i;
        s.erase(prefix[i]);
        ++i;
    }

    cout << answer << endl;

    return 0;
}

