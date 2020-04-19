#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    string s; cin >> s;
    int freq[26] = {0};

    int count{0};
    for (char c : s)
    {
        freq[c - 'a']++;
        if (freq[c - 'a'] == 1)
        {
            ++count;
        }
    }

    cout << vector<string>{"CHAT WITH HER!","IGNORE HIM!"}[count & 1] << endl;

    return 0;
}

