//
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int>& smaller = (nums1.size() <= nums2.size() ? nums1 : nums2);
    vector<int>& larger  = (nums1.size() <= nums2.size() ? nums2 : nums1);

    const int n(nums1.size() + nums2.size() + 1);
    const int k(n / 2);
    int low = 0;
    int high = smaller.size() - 1;
    while (low <= high)
    {
        int smallP = (low + high) / 2;
        int largeP = n / 2 - smallP; // Why?

        const int smallPMax = !smallP ? INT_MIN : smaller[smallP - 1];
        const int largePMax = !largeP ? INT_MIN : larger[largeP - 1];

        const int smallNMin = smallP >= smaller.size() ? 
            INT_MAX : smaller[smallP];
        const int largeNMin = largeP >= larger.size() ? 
            INT_MAX : larger[largeP];

        if (smallPMax <= largeNMin && largePMax <= smallNMin)
        {
            if ((n - 1) % 2)
            {
                return static_cast<double>(max(smallPMax, largePMax));
            }
            else
            {
                return max(smallPMax, largePMax) + 
                       min(smallNMin, largeNMin) / 2.0;
            }
        }
        else if (smallPMax > largeNMin)
        {
            high = smallP - 1;
        }
        else
        {
            low = smallP + 1;
        }
    }
}

int main()
{
    {
        // 1 3 7 8 9 *11* 15 18 19 21 25
        std::vector<int> a{ 1, 3, 8, 9, 15 };
        std::vector<int> b{ 7, 11, 18, 19, 21, 25 };

        const double Result = findMedianSortedArrays(a, b);
        cout << ((abs(Result - 11.0) < 1e-6) ? "TRUE" : "FALSE") << endl;
        cout << Result << endl;
    }

    {
        // 3, 5, 7, 9, *11, 16*, 23, 26, 31, 35
        std::vector<int> a{ 23, 26, 31, 35 };
        std::vector<int> b{ 3, 5, 7, 9, 11, 16 };

        const double Result = findMedianSortedArrays(a, b);
        cout << ((abs(Result - 13.5) < 1e-6) ? "TRUE" : "FALSE") << endl;
        cout << Result << endl;
    }

    return 0;
}
