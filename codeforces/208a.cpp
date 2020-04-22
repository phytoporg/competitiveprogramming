#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    string s; cin >> s;
    string copyTo(s);

    int current{0};
    int copyCount{0};

    char ref[] = "WUB";
    char* pRef{ref};
    char* pSearch{&s[0]};

    int n(s.size());
    bool justWubbed{false};
    while (current < n)
    {
        while(*pRef > 0 && *pSearch > 0)
        {
            if (*pRef == *pSearch)
            {
                ++pRef; ++pSearch;
            }
            else
            {
                ++pSearch;
                break;
            }
        }

        if (*pRef > 0)
        {
            if (justWubbed && copyCount)
            {
                copyTo[copyCount++] = ' ';
            }
            justWubbed = false;

            copyTo[copyCount++] = s[current++];
            pSearch = &s[current];
        }
        else
        {
            current += 3;
            justWubbed = true;
        }

        pRef = ref;
    }

    copyTo.resize(copyCount);
    cout << copyTo << endl;

    return 0;
}

