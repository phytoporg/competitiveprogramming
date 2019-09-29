#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned x;
    cin >> x;

    static const vector<unsigned> StepSizes{5, 4, 3, 2, 1};
    unsigned stepCount{0};

    while(x > 0)
    {
        for (const auto StepSize : StepSizes)
        {
            if (StepSize <= x)
            {
                const int StepsTaken{x / StepSize};
                x -= (StepsTaken * StepSize);
                stepCount += StepsTaken;
            }
        }
    }

    cout << stepCount;
}
