#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    string s;
    cin >> s;

    int luckyCount{0};
    for (char& c : s)
    {
        luckyCount += (c == '4' || c == '7');
    }

    cout << vector<string>{"NO", "YES"}[luckyCount == 4 || luckyCount == 7] << endl;

    return 0;
}
