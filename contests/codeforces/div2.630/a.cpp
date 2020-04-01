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

        x += b - a;
        y += d - c;

        const bool x0 = (a == b && b == 0);
        const bool y0 = (c == d && d == 0);
        if ((x >= x1 && x <= x2 && y >= y1 && y <= y2 && 
            (x1 < x2 || x0) && (y1 < y2 || y0)))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

