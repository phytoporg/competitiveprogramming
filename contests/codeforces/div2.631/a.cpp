#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; int x;
        cin >> n >> x;

        unordered_set<int> s;
        while(n--) 
        { 
            int ai;
            cin >> ai; 
            s.insert(ai);
        }

        int i{1};
        while(x || s.count(i))
        {
            if (!s.count(i))
            {
                --x;
            }

            ++i;
        }

        if (!s.count(i))
        {
            cout << i - 1 << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}

