#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

string modify(const string& s, int n, int k)
{
    string pre = s.substr(k - 1, n - k + 1);
    string post = s.substr(0, k - 1);
    if ((n & 1) == (k & 1))
    {
        reverse(begin(post), end(post));
    }

    return pre + post;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;

        int minK{1};
        string minString{modify(s, n, 1)};
        for (int k = 2; k <= n; ++k)
        {
            string tmp = modify(s, n, k);
            if (tmp < minString)
            {
                minString = tmp;
                minK = k;
            }
        }

        cout << minString << "\n" << minK << endl;
    }

    return 0;
}

