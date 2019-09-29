#include <bits/stdc++.h>
using namespace std;

using tup = tuple<int, int>;

bool isGood(const vector<tup>& v)
{
    return !is_sorted(begin(v), end(v), 
                [](const tup& a, const tup& b)
            {
                return get<0>(a) < get<0>(b);
            }) &&
           !is_sorted(begin(v), end(v), 
                [](const tup& a, const tup& b)
            {
                return get<1>(a) < get<1>(b);
            });
}

int main()
{
    int n;
    cin >> n;
    vector<tup> pairs;
    pairs.reserve(n);

    int a, b;
    while(cin >> a >> b) { pairs.emplace_back(a, b); }

    vector<int> indices(n);
    for(int i = 0; i < n; ++i)
    {
        indices[i] = i;
    }

    long long numPermutations{0};
    do
    {
        vector<tup> thisPermutation(n);
        transform(begin(indices), end(indices), begin(thisPermutation),
                [&pairs](const int i){ 
                    return pairs[i];
                });
        if (isGood(thisPermutation))
        {
            numPermutations++;
            numPermutations %= 998244353LL;
            for (auto [f, s] : thisPermutation)
            {
                cout << "(" << f << "," << s << ")";
            }
            cout << "\n";
        }
    } while(next_permutation(begin(indices), end(indices)));

    cout << numPermutations;

    return 0;
}
