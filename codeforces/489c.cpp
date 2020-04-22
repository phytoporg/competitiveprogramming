#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

void fillString(int count, string& s)
{
    int i(s.size() - 1);
    while(count)
    {
        if (s[i] < '9')
        {
            s[i]++;
        }
        else if (s[i] == '9')
        {
            s[--i]++;
        }

        --count;
    }
}

int main()
{
    int m, s; cin >> m >> s;
    int mx = 9 * m;

    if (s > mx || (s == 0 && m > 1)) 
    { 
        cout << "-1 -1" << endl; return 0; 
    }

    string minstr(m, '0');
    minstr[0] = s > 0 ? '1' : '0';
    fillString(s - (s > 0), minstr);

    string maxstr(m, '0');
    fillString(s, maxstr);
    reverse(begin(maxstr), end(maxstr));

    cout << minstr << ' ' << maxstr << endl;

    return 0;
}
