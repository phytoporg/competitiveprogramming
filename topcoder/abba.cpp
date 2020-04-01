#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

bool prune(vector<char>& v, string& t)
{
    string s(begin(v), end(v));
    if (t.find(s) != string::npos) return false;

    reverse(begin(s), end(s));
    if (t.find(s) != string::npos) return false;

    return true;
}

bool bt(string& t, vector<char>& v, size_t i)
{
    if (i == t.length())
    {
        return string(begin(v), end(v)) == t;
    }

    bool result1{false};
    reverse(begin(v), end(v));
    v.push_back('B');
    if (!prune(v, t)) result1 = bt(t, v, i+1);
    v.pop_back();
    reverse(begin(v), end(v));

    bool result2{false};
    if (!result1)
    {
        v.push_back('A');
        if (!prune(v, t)) result2 = bt(t, v, i+1);
        v.pop_back();
    }
    
    return result1 || result2;
}

string canObtain(string s, string t)
{
    size_t i = 1;
    vector<char> v(begin(s), end(s));
    return (bt(t, v, i) ? "Possible" : "Impossible");
}

int main()
{
    string s;
    string t;
    cin >> s >> t;

    cout << canObtain(s, t) << endl;
    return 0;
}
