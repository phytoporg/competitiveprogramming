#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << (x) << endl)

using ll = long long;
using ull = unsigned long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;

        int prev{1};
        vector<int> steps{prev};

        int sum{1};
        while(sum < n)
        {
            int next = prev * 2;
            int diff{n - sum};
            if (diff <= next)
            {
                steps.insert(
                    lower_bound(begin(steps), end(steps), diff),
                    diff);
            }
            else
            {
                steps.push_back(next);
            }

            prev = next;
            sum += next;
        }

        cout << steps.size() - 1 << endl;
        for (size_t i = 1; i < steps.size(); ++i) 
        { 
            cout << steps[i] - steps[i - 1] << ' ';
        }
        cout << endl;
    }

    return 0;
}

