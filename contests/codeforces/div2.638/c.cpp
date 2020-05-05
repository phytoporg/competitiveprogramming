#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s; cin >> s;
        sort(begin(s), end(s));

        if (k == 1)
        {
            cout << s << endl;
        }
        else
        {
            set<char> preset;
            for (int i = 0; i < k; ++i)
            {
                preset.insert(s[i]);
            }

            set<char> postset;
            for (int i = k; i < n; ++i)
            {
                postset.insert(s[i]);
            }

            if (preset.size() > 1)
            {
                cout << s[k - 1] << endl;
            }
            else if (preset.size() == 1 && postset.size() <= 1)
            {
                int distrib{(n - k) / k + !!(n % k)};
                cout << s[k - 1];
                for (int i = 0; i < distrib; ++i)
                {
                    cout << s[k];
                }
                cout << endl;
            }
            else if (preset.size() == 1 && postset.size() > 1)
            {
                cout << s.substr(k - 1) << endl;
            }
        }
    }

    return 0;
}

