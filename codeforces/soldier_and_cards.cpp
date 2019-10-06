#include <bits/stdc++.h>
using namespace std;

static map<string, bool> stateVisited;
string encodeState(const deque<int>& p1, const deque<int>& p2)
{
    stringstream ss;
    for (size_t i = 0; i < p1.size(); ++i)
    {
        ss << p1[i] << " ";
    }
    ss << "|";

    for (size_t i = 0; i < p2.size(); ++i)
    {
        ss << p2[i] << " ";
    }

    return ss.str();
}

int main()
{
    int n; cin >> n;
    int k1; cin >> k1;
    deque<int> p1(k1);
    for(int i = 0; i < k1; ++i)
    {
        cin >> p1[i];
    }

    int k2; cin >> k2;
    deque<int> p2(k2);
    for(int i = 0; i < k2; ++i)
    {
        cin >> p2[i];
    }

    int wincounts[2] = {};
    while(!p1.empty() && !p2.empty())
    {
        string e = encodeState(p1, p2);
        if (stateVisited.find(e) != end(stateVisited))
        {
            cout << -1;
            return 0;
        }
        else
        {
            stateVisited[e] = true;
        }

        int c[] = {p1.front(), p2.front()};
        int winner = c[0] > c[1] ? 0 : 1;
        wincounts[winner]++;

        p1.pop_front(); p2.pop_front();
        if (!winner)
        {
            p1.push_back(c[1]); p1.push_back(c[0]);
        }
        else
        {
            p2.push_back(c[0]); p2.push_back(c[1]);
        }
    }

    cout << wincounts[0] + wincounts[1] << " " 
         << (wincounts[0] > wincounts[1] ? "1" : "2");

    return 0;
}
