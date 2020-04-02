#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using ull = unsigned long long;
array<ull, 64> colmasks{};
array<ull, 64> rowmasks{};

int longest(vector<int> values)
{
    size_t n{values.size()};
    sort(begin(values), end(values));

    map<int, int> freqs;
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            int diff = values[j] - values[i];
            bool counted{false};
            if (!freqs.count(diff)) {
                freqs[diff] = 1; 

                colmasks[diff] |= (1 << j);
                rowmasks[diff] |= (1 << i);
                counted = true;
            }
            else if (!(colmasks[diff] & (1 << j)) &&
                     !(rowmasks[diff] & (1 << i))) 
            {
                freqs[diff]++; 

                colmasks[diff] |= (1 << j);
                rowmasks[diff] |= (1 << i);
                counted = true;
            }
        }
    }

    int maxFreq{0};
    for (auto& [v, freq] : freqs)
    {
        if (freq > maxFreq) { maxFreq = freq; }
    }

    return maxFreq + 1;
}

int main()
{
    vector<int> values;
    int v;
    while (cin >> v)
    {
        values.push_back(v);
    }

    cout << longest(values) << endl;

    return 0;
}
