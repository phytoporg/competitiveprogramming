#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

vector<bool> seen(200001, false);
bool isSolution(const vector<int>& a, int p1, int p2)
{
    fill(begin(seen), begin(seen) + p1 + 1, false);
    for (int i = 0; i < p1; ++i)
    {
        if (seen[a[i]]) { return false; }
        else { seen[a[i]] = true; }
    }

    for (int i = 1; i <= p1; ++i)
    {
        if (!seen[i]) { return false; }
    }

    int n(a.size());
    fill(begin(seen), begin(seen) + p2 + 1, false);
    for (int i = p1; i < n; ++i)
    {
        if (seen[a[i]]) { return false; }
        else { seen[a[i]] = true; }
    }

    for (int i = 1; i <= p2; ++i)
    {
        if (!seen[i]) { return false; }
    }

    return true;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);

        int maxVal = -1;
        for (int& ai : a) { cin >> ai; maxVal = max(ai, maxVal); }

        int x = maxVal;
        int y = n - maxVal;

        if (maxVal >= n)
        {
            cout << "0\n";
            continue;
        }

        bool one{isSolution(a, x, y)};
        bool two{isSolution(a, y, x) && x != y};

        if (one && two) { cout << "2\n" 
                               << x << ' ' << y << '\n'
                               << y << ' ' << x << '\n'; }
        else if (one) { cout << "1\n" << x << ' ' << y << '\n'; }
        else if (two) { cout << "1\n" << y << ' ' << x << '\n'; }
        else { cout << '0' << '\n'; }
    }

    return 0;
}

