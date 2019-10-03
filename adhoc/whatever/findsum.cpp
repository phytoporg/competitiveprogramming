#include <bits/stdc++.h>
using namespace std;

//
// Given an array A and value k, find i, j such that
// A[i] + A[j] == k, if such i and j exist.
//

int main()
{
    int n, k; cin >> n >> k;
    vector<int> v(n); int i{0}; while(cin >> v[i++]);

    unordered_map<int, int> c;
    for (size_t i = 0; i < v.size(); ++i)
    {
        const int key{k - v[i]};
        if (c.find(key) != c.end())
        {
            cout << "FOUND: " << v[i] << "(" << i << "), " 
                 << key  << "(" << c[key] << ")" <<  endl;
            return 0;
        }

        c[v[i]] = i;
    }

    cout << "NOPE";

    return 0;
}
