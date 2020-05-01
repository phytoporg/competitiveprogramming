#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int h{n / 2};

        int a{1 << n};
        for (int i = 1; i < h; ++i)
        {
            a |= (1 << i);
        }

        int b{0};
        for (int i = h; i < 2*h; ++i)
        {
            b |= (1 << i);
        }

        cout << a - b << endl;
    }

    return 0;
}
