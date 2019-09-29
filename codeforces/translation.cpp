#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    if (a.length() != b.length()) { cout << "NO"; return 0; }
    
    char const* pA{a.data()};
    char const* pB{&(b.back())};
    for(size_t i = 0; i < a.length(); ++i)
    {
        if (*pA != *pB) { cout << "NO"; return 0; }
        ++pA;
        --pB;
    }
    
    cout << "YES";
    return 0;
}
