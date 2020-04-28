#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<bool> rused(rows, false);
    vector<bool> cused(rows, false);

    int rLeft = rows;
    int cLeft = cols;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            char s; cin >> s;
            if (s == 'S')
            {
                if (!rused[r])
                {
                    rused[r] = true;
                    rLeft--;
                }

                if (!cused[c]) 
                {
                    cused[c] = true;
                    cLeft--;
                }
            }
        }
    }

    int eaten{rLeft * cols + cLeft * (rows - rLeft)};
    cout << eaten << endl;

    return 0;
}

