#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < 2 * k; ++i)
    {
        int tmp; cin >> tmp >> tmp;
    }

    vector<char> moves;
    char uOrD[] = {'U', 'D'};
    char lOrR[] = {'L', 'R'};

    int vDir = 1;
    int hDir = 1;
    for (int c = 0; c < m; ++c)
    {
        for (int r = 0; r < n - 1; ++r)
        {
            moves.push_back(uOrD[vDir]);
        }

        moves.push_back(lOrR[hDir]);
        vDir = !vDir;
    }

    hDir = !hDir;
    for (int c = 0; c < m; ++c)
    {
        for (int r = 0; r < n - 1; ++r)
        {
            moves.push_back(uOrD[vDir]);
        }

        moves.push_back(lOrR[hDir]);
        vDir = !vDir;
    }

    cout << moves.size() << '\n';
    for (char& move : moves) { cout << move; }
    cout << endl;

    return 0;
}

