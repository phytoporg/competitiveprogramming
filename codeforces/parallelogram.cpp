#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b)
{
    return make_pair(a.first - b.first, a.second - b.second);
}

pair<int, int> operator-(const pair<int, int>& a)
{
    return make_pair(-a.first, -a.second);
}

int main()
{
    int x, y;
    cin >> x >> y;
    auto p1 = make_pair(x,y);
    cin >> x >> y;
    auto p2 = make_pair(x,y);
    cin >> x >> y;
    auto p3 = make_pair(x,y);

    auto s1 = p2 - p1;
    auto s2 = p3 - p2;
    auto s3 = p1 - p3;

    cout << "3\n";
    set<pair<int, int>> s;
    s.insert(p1 - s2);
    s.insert(p1 + s2);

    s.insert(p2 - s3);
    s.insert(p2 + s3);

    s.insert(p3 - s1);
    s.insert(p3 + s1);

    for (auto& p : s)
    {
        cout << p.first << ' ' << p.second << "\n";
    }

    return 0;
};

