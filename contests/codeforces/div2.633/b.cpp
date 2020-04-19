#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        sort(begin(a), end(a));

        vector<int> ans;
        int len(a.size());
        int i{len / 2 - (len & 1 ? 0 : 1)};
        int d{1}; int sign{1};
        while(i >= 0 && i < len)
        {
            ans.push_back(a[i]);
            i += (d * sign);
            ++d;
            sign = -sign;
        }

        for (int& ai : ans) { cout << ai << " \n"[&ai == &ans.back()]; }
    }

    return 0;
}
