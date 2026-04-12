/*
Saturday, April 11th, 2026

Topic: Dynamic Programming, array

Basic Idea:
We use dynamic programming to solve this problem. 
At each position, we decide whether to extend the existing subarray or start a new one.
Unlike the previous solution, we can optimize space by using two variables instead of a dp array.


Time Complexity: O(n), where n is the length of the input array. We traverse the array once to fill the dp array.
Space Complexity: O(1), where n is the length of the input array.
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            ans = max(ans, curr);
        }

        return ans;
    }
};