#include <bits/stdc++.h>
using namespace std;

string input = "a";

bool isPalindrome(const string& s, size_t begin, size_t end)
{
    while(begin < end)
    {
        if (s[begin] != s[end]) { return false; }
        ++begin; --end;
    }

    return true; 
}

string longestPalindromeString(string s)
{
    unordered_map<char, vector<size_t>> locationMap;
    for (size_t i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (!locationMap.count(c))
        {
            locationMap[c] = vector<size_t>{i};
        }
        else
        {
            locationMap[c].push_back(i);
        }
    }

    size_t start{0};
    size_t end{0};
    size_t maxLen{1};
    for (size_t i = 0; i < s.size(); ++i)
    {
        auto& t = locationMap[s[i]];
        for (size_t ti = t.size() - 1; t[ti] > i; --ti)
        {
            if (maxLen < (t[ti] - i + 1) && isPalindrome(s, i, t[ti]))
            {
                maxLen = t[ti] - i + 1;
                start = i; end = t[ti];
                break;
            }
        }
    }

    return string(s, start, maxLen);
}

int main()
{
    cout << longestPalindromeString(input) << endl;
    return 0;
}
