#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    string g, h, l;
    cin >> g >> h >> l;

    string names = g + h;
    bool good = (names.size() == l.size());
    if (good)
    {
        int freq1[26] = {0};
        for (char c : names)
        {
            freq1[c - 'A']++;
        }

        int freq2[26] = {0};
        for (char c : l)
        {
            freq2[c - 'A']++;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (freq1[i] != freq2[i])
            {
                good = false;
                break;
            }
        }
    }

    cout << vector<string>{"NO", "YES"}[good] << endl;

    return 0;
}

