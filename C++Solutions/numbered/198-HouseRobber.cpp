/*
Tuesday, March 31st, 2026

Topic: Dynamic Programming

Basic Idea:
We can use dynamic programming to solve this problem.
1. We can create a 1D array of integers to store the maximum amount of money
that can be robbed up to each house.
2. We can initialize the first three elements of the array with the amount of money
in the first three houses, since we can only rob one of them.
3. Then, for each house from the fourth house onwards, we can calculate the maximum
amount of money that can be robbed by adding the amount of money in that house to the maximum
of the amount of money that can be robbed from the previous two houses (since we cannot rob adjacent houses).
4. We can return the maximum amount of money that can be robbed, which is the maximum of the amount of money that can be robbed from the last two houses.

Time Complexity: O(n), where n is the number of houses.
Space Complexity: O(n), where n is the number of houses.

Notes:
- we can also optimize the space complexity to O(1) by only keeping track of the last three values instead of the entire array.
- we need to consider the case when there are only one or two houses, since we can only rob one of them.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();

        if (l == 1) {
            return nums[0];
        }

        if (l == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(l ,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        for (int i = 3; i < l; i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
        }

        return max(dp[l - 2], dp[l - 1]);
    }
};