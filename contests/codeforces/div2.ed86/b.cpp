#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int T; cin >> T;
    while(T--)
    {
        string t; cin >> t;

        int count0{0};
        int count1{0};

        for (char& c : t)
        {
            if (c == '0') ++count0;
            else ++count1;
        }

        if (count0 == 0 || count1 == 0)
        {
            cout << t << endl;
        }
        else
        {
            string s;
            int expected{0};
            for (char& c : t)
            {
                if (c != (expected + '0'))
                {
                    s.push_back('0' + expected);
                    s.push_back(c);
                }
                else
                {
                    s.push_back('0' + expected);
                    expected = !expected;
                }
            }

            cout << s << endl;
        }
    }

    return 0;
}
