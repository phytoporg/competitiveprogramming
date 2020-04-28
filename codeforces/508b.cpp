#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    // input is always odd
    // must swap first digit with an even digit
    // swap with the left-most even digit for which the first digit is larger

    string s;
    cin >> s;

    char first(s.back());
    int n(s.size());
    int swapIndex{-1};
    int lastEven{-1};
    for (int i = 0; i < n; ++i)
    {
        char c{s[i]};
        if (!(c & 1))
        {
            lastEven = i;
            if (c < first)
            {
                swapIndex = i; break;
            }
        }
    }

    if (lastEven < 0) { s = "-1"; }
    else if (swapIndex < 0)
    {
        swap(s[lastEven], s.back());
    }
    else
    {
        swap(s[swapIndex], s.back());
    }

    cout << s << endl;

    return 0;
};
