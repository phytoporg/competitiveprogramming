#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        set<int> s;

        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i)
        {
            int ai; cin >> ai;
            s.insert(ai);
        }

        int len(s.size());
        if (len > k)
        {
            cout << "-1" << endl;
        }
        else
        {
            int newval{1};
            while (len < k)
            {
                if (!s.count(newval))
                {
                    s.insert(newval);
                    ++len;
                }
                ++newval;
            }

            cout << n * len << endl;
            for (int i = 0; i < n; ++i)
            {
                for (int j : s)
                {
                    cout << j << ' ';
                }
            }

            cout << endl;
        }
    }

    return 0;
}

