#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    size_t numLower{0};
    for (char& c : s) { numLower += (c > 'Z'); c |= (1<<5); }

    if (numLower < (s.size() - numLower))
    {
        for (char& c : s) { c &= ~(1<<5); }
    }

    cout << s;

    return 0;
}
