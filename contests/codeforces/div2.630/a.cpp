//
// didn't get this :(
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int dx = b - a;
        int dy = d - c;
        int px = x + dx; int py = y + dy;

        bool s{false};
        if ((b > a && (x2 - x) >= (b - a)) ||
            (b == a && 
               ((x2 - x >= 1 || (x - x1 >= 1)) || (b == 0))) ||
            (a > b && (x - x1) >= (a - b)))
        {
            s = true;
        }

        if (s)
        {
            if ((d > c && (y2 - y) >= (d - c)) ||
                (d == c && 
                    ((y2 - y >= 1 || (y - y1 >= 1)) || (d == 0))) ||
                (c > d && (y - y1) >= (c - d)))
            {
                s = true;
            }
        }

        if (s) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

