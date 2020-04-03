#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

vector<int> z(const string& s)
{
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    for (int i = 1; i < n; ++i)
    {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            ++z[i];
        }
    }

    return z;
}

int main()
{
    string s;
    cin >> s;

    auto zv = z(s);
    for (int& zi : zv)
    {
        cout << zi << " \n"[&zi == &zv.back()];
    }

    return 0;
}
