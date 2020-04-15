#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;
int main()
{
    int n; cin >> n;

    map<int, ull> m;
    for (int i = 1; i <= n; ++i)
    {
        int b; cin >> b;
        int diff = i - b;
        if (!m.count(diff))
        {
            m[diff] = b;
        }
        else
        {
            m[diff] += b;
        }
    }

    using p = pair<int, ull>;
    auto it = max_element(begin(m), end(m), [](const p& a, const p& b)
            {
                return a.second < b.second;
            });
    cout << it->second << endl;
    return 0;
}

