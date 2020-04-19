#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, h;
        cin >> h >> n >> m;

        while ((n || m) && h > 0)
        {
            int tmp1{h};
            if (n)
            {
                tmp1 /= 2;
                tmp1 += 10;
            }

            int tmp2{h};
            if (m)
            {
                tmp2 -= 10;
            }

            if (n && h > 20)
            {
                h = tmp1; --n;
            }
            else if (m)
            {
                h = tmp2; --m;
            }
            else
            {
                break;
            }
        }

        cout << vector<string>{"NO", "YES"}[h <= 0] << endl;
    }

    return 0;
}

