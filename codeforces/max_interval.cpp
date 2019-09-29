#include <iostream>
#include <vector>

using namespace std;

int doIt(const vector<int>& A)
{
    int sum{0};
    int start{0};
    int length{0};
    
    int bestSum{0};
    int bestStart{0};
    int bestLength{0};
    
    for(size_t i = 0; i < A.size(); ++i)
    {
        const int Current{A[i]};
        cout << "Current = " << Current << endl;
        cout << "sum = " << sum << endl;
        cout << "bestSum = " << bestSum << endl;
        if (sum + Current > bestSum)
        {
            sum += Current;
            ++length;
            
            bestSum = sum;
            bestStart = start;
            bestLength = length;
        }
        else if (sum + Current < 0)
        {
            sum = 0;
            start = i + 1;
            length = 0;
        }
        else
        {
            sum += Current;
            ++length;
        }
    }
    
    return bestSum;
}

int main()
{
    vector<int> A{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << doIt(A) << endl;
}

