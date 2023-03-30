/*
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Example 2:
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

Constraints:
    2 <= nums.length <= 10^5
    1 <= nums[i], minK, maxK <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        int lastInvalidElement = -1, lastMinKIdx = -1, lastMaxKIdx = -1;
        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= minK && nums[i] <= maxK)
            {
                lastMinKIdx = (nums[i] == minK) ? i : lastMinKIdx;
                lastMaxKIdx = (nums[i] == maxK) ? i : lastMaxKIdx;

                count += max(0, min(lastMinKIdx, lastMaxKIdx) - lastInvalidElement);
            }
            else
            {
                lastInvalidElement = i;
                lastMinKIdx = -1;
                lastMaxKIdx = -1;
            }
        }
        return count;
    }
};