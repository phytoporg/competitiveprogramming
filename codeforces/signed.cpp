#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 0xFFFF;
    i <<= 16;
    i >>= 16;

    cout << i << endl;

    if (i < 0)
    {
        i += 0x10000;
    }

    cout << i << endl;

    return 0;
}
