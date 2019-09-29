#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using tup = pair<int, int>;

static const ll maxn(3*10e5 + 5);
static int fc[maxn] = {};
static int sc[maxn] = {};

int main()
{
    map<tup, int> pc;
    vector<tup> a;

    ll m{998244353};
    ll c{1}, f{1}, s{1}, p{1};

    int n; cin >> n;
    int fr, sr;
    while(cin >> fr >> sr) { a.emplace_back(fr, sr); }

    int i{0};
    for (const auto& t : a)
    {
        auto [fi, si] = t;
        c = (c * ++i) % m;
        f = (f * ++fc[fi]) % m;
        s = (s * ++sc[si]) % m;
        p = (p * ++pc[t]) % m;
    }

    c = (c - (f + s - p)) % m;
    sort(begin(a), end(a));
    if (!is_sorted(begin(a), end(a),
            [](const tup& x, const tup& y)
            {
                return get<1>(x) < get<1>(y);
            }))
    {
        c = (c - p) % m;
    }

    cout << (c % m + m) % m;

    return 0;
}
