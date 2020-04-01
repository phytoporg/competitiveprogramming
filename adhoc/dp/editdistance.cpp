#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

using Grid = vector<vector<int>>;
int EditDistance(const string& a, const string& b)
{
    if (a.empty()) { return b.length(); }
    else if (b.empty()) { return a.length(); }

    size_t m{a.size()};
    size_t n{b.size()};
    Grid grid(m + 1, vector<int>(n + 1, 0));
    grid[0][0] = a[0] != b[0];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0) { 
                cout << grid[i][j] << ' ';
                continue; 
            }

            const int x = i > 0 ? grid[i-1][j] + 1: INT_MAX - 1;
            const int y = j > 0 ? grid[i][j-1] + 1: INT_MAX - 1;
            const int z = j > 0 && i > 0 ? grid[i-1][j-1] : INT_MAX - 1;
            grid[i][j] =
                min(x, min(y, z + static_cast<int>(a[i] != b[j])));
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    return grid[m-1][n-1];
}

int main()
{
    string a; string b;
    cin >> a >> b;

    cout << EditDistance(a, b) << endl;

    return 0;
}

