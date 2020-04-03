#include <bits/stdc++.h>
using namespace std;

#define PRINTVAR(x) (cout << #x << " is " << x << endl)

vector<vector<int>> threeSum(vector<int>& nums)
{
    if (nums.empty()) { return vector<vector<int>>{}; }

    sort(begin(nums), end(nums));

    int n{nums.size()};
    vector<vector<int>> ret;
    for (int i = 0; i < n; ++i)
    {
        int j{i + 1};
        int k{n - 1};
        if (i > 0 && nums[i - 1] == nums[i]) { continue; }

        while(j < k)
        {
            if (nums[j] + nums[k] + nums[i] < 0)
            {
                ++j;
            }
            else if (nums[j] + nums[k] + nums[i] > 0)
            {
                --k;
            }
            else 
            {
                ret.push_back({nums[i], nums[j], nums[k]});
                ++j;
                while(j < k && nums[j] == nums[j - 1]) ++j;
            }
        }
    }

    return ret;
}

int main()
{
    int n;
    vector<int> nums;
    while (cin >> n) { nums.push_back(n); }

    auto v = threeSum(nums);
    for (auto& value : v)
    {
        cout << value[0] << ' ' << value[1] << ' ' << value[2] << '\n';
    }

    return 0;
}
