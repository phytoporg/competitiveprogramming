#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, m;
    cin >> n >> m;

    map<string, string> dictionary;
    while(m--)
    {
        string a, b;
        cin >> a >> b;
        dictionary[a] = (a.length() <= b.length() ? a : b);
        dictionary[b] = dictionary[a];
    }

    while (n--)
    {
        string s; cin >> s;
        cout << dictionary[s] << " \n"[n == 0];
    }

    return 0;
}

