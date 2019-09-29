#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h; cin >> n; cin >> h;

    int width{0};
    int a_i;
    while(cin >> a_i)
    {
        width += 1 + (a_i > h);
    }

    cout << width;
}
