#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

int maxSubArray(vector<int>& nums)
{
    int sum{0};
    int maxSum{0};
    int n{nums.size()};
    for(int i = 0; i < n; ++i)
    {
        sum = max(nums[i], nums[i] + sum);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main()
{
    vector<int> a;
    int n;
    while(cin >> n) { a.push_back(n); }

    cout << maxSubArray(a) << endl;
        
    return 0;
}
