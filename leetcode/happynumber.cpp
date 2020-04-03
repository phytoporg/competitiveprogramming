#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

bool isHappy(int n)
{
    set<int> seen;
    while(n != 1)
    {
        if (seen.count(n)) { return false; }
        seen.insert(n);

        int tmp{0};
        while(n)
        {
            int digit = (n % 10);
            n /= 10;
            tmp += digit * digit;
        }

        n = tmp;
    }

    return true;
}

int main()
{
    int n; cin >> n;

    cout << (isHappy(n) ? "Happy" : "Not happy") << endl;

    return 0;
}
