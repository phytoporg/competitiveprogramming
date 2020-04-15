#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int main()
{
    int n, k;
    cin >> n >> k;

    set<int> assigned;
    vector<int> assignments(k);
    for (int i = 0; i < k; ++i)
    {
        int ai; cin >> ai;
        assignments[i] = ai;
        assigned.insert(ai);
    }

    int segmentIndex{1};
    for (int child = 0; child < k; ++child)
    {
        for (int slice = 0; slice < n; ++slice)
        {
            if (slice == 0)
            {
                cout << assignments[child] << ' ';
            }
            else
            {
                while(assigned.count(segmentIndex) > 0)
                {
                    ++segmentIndex;
                }

                cout << segmentIndex++ << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}

