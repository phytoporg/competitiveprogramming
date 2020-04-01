#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

string canObtain(string s, string t)
{
    while (t.length() > s.length())
    {
        const char back = t.back();
        t.pop_back();

        if (back == 'B') { reverse(begin(t), end(t)); }
    }

    assert(t.length() == s.length());
    return (t == s ? "Possible" : "Impossible");
}

int main()
{
    string s;
    string t;
    cin >> s >> t;

    cout << canObtain(s, t) << endl;

    return 0;
}

