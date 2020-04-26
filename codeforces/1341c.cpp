#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        int current{0};
        int seqMin{0};
        bool success{true};
        while(current < n)
        {
            if (current < n - 1)
            {
                int next{a[current + 1]};
                if (next < a[seqMin]) { seqMin = current + 1; }
                else if (next - a[current] != 1)
                {
                    cout << "No\n";
                    success = false;
                    break;
                }

                ++current;
            }
            else
            {
                break;
            }
        }

        if (success) { cout << "Yes\n"; }
    }

    return 0;
}

