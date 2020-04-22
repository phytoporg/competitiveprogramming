#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    string s;
    cin >> s;

    int nLower{0};
    int nUpper{0};
    
    for (char c : s) 
    {
        if (c < 'a') 
        {
            nUpper++;
        }
        else
        {
            nLower++;
        }
    }

    for (char& c : s)
    {
        if (nUpper > nLower && c >= 'a')
        {
            c -= 32;
        }
        else if (nLower >= nUpper && c < 'a')
        {
            c += 32;
        }
    }

    cout << s << endl;

    return 0;
}
