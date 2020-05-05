#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin >> n;    

    if (n & 1)
    {
        cout << "YES\n";
        vector<int> offsets{n, 1, -n, 1};
        vector<int> values(2 * n);

        int index{0};
        for (int i = 0; i < 2 * n; ++i)
        {
            values[index] = i;
            index += offsets[i % 4];
        }

        for (int& vi : values) { cout << vi + 1 << ' '; }
    }
    else
    {
        cout << "NO";
    }

    cout << endl;

    return 0;
}
