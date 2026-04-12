/*
Saturday, April 11th, 2026

Topic: Dynamic Programming, array

Basic Idea:
We use dynamic programming to solve this problem. 
At each position, we decide whether to extend the existing subarray or start a new one.


Time Complexity: O(n), where n is the length of the input array. We traverse the array once to fill the dp array.
Space Complexity: O(n), where n is the length of the input array.

*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        int ans = INT_MIN;
        dp[0] = nums[0];
        ans = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};