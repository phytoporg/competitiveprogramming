#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int maxArea(vector<int>& a)
{
    if (a.empty() || a.size() == 1) { return 0; }

    int maxArea{-1};
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a.size(); ++j)
        {
            int area = (max(i, j) - min(i, j)) * min(a[i], a[j]);
            if (area > maxArea) { maxArea = area; }
        }
    }

    return maxArea;
}

int main()
{
    vector<int> a;
    int n;
    while(cin >> n) { a.push_back(n); }

    cout << maxArea(a) << endl;

    return 0;
}
