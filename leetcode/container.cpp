#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int maxArea(vector<int>& a)
{
    if (a.empty() || a.size() == 1) { return 0; }

    int i{0};
    int j(a.size() - 1);

    int m{-1};
    while(i < j)
    {
        m = max((j - i) * a[i], m);
        if (a[i] < a[j]) { ++i; }
        else { --j; }
    }

    return m;
}

int main()
{
    vector<int> a;
    int n;
    while (cin >> n) { a.push_back(n); }

    cout << maxArea(a) << endl;

    return 0;
}
