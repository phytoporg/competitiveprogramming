#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; ++k)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int& ai : a) { cin >> ai; }

        int m{1};

        vector<int> c(n, -1);
        for (int i = 0; i < a.size(); ++i)
        {
            if (c[i] > 0) 
            { 
                continue; 
            }

            int notColored{0};
            for (int j = i; j < a.size(); ++j)
            {
                if (c[j] > 0) 
                { 
                    continue; 
                }
                else
                {
                    notColored++;
                }

                if (__gcd(a[i], a[j]) > 1) { c[j] = m; }
            }

            if (!notColored) { break; }
            if (i < a.size() - 1) { ++m; };
        }

        cout << m << endl;
        for (int& ci : c) { cout << ci << " \n"[&ci == &c.back()]; }
    }

    return 0;
}

