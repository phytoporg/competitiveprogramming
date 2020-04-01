#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; int k;
        cin >> n >> k;

        string s;
        cin >> s;

        const int o{k & 1};
        vector<map<char, int>> freqs(k / 2 + o);
        for (int c = 0; c < s.length(); c += k)
        {
            for (int i = 0; i < (k / 2 + o); ++i)
            {
                {
                    auto& t = freqs[i];
                    if (!t.count(s[c + i])) { t[s[c + i]] = 1; }
                    else { t[s[c + i]]++; }
                }

                if (!(o && i == (k / 2)))
                {
                    int j = k - i - 1;
                    auto& t = freqs[i];
                    if (!t.count(s[c + j])) { t[s[c + j]] = 1; }
                    else { t[s[c + j]]++; }
                }
            }
        }

        int moves{0};
        for (int i = 0; i < freqs.size(); ++i)
        {
            auto& t = freqs[i];
            int maxFreq{-1};
            for (const auto& [c, f] : t)
            {
                if (f > maxFreq) { maxFreq = f; }
            }

            if (o && i == (k / 2))
            {
                moves += (n / k) - maxFreq;
            }
            else
            {
                moves += 2 * (n / k) - maxFreq;
            }
        }

        cout << moves << endl;
    }

    return 0;
};

