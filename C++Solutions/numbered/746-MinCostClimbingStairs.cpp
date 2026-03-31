/*
Tuessay, March 31st, 2026

Topic: Dynamic Programming

Basic Idea:
We can use dynamic programming to solve this problem.
1. We can create a 1D array of integers to store the minimum cost to reach each step.
2. We can initialize the first two elements of the array with the cost of the first two steps, since we can start from either of them.
3. Then, for each step from the third step onwards, we can calculate the minimum cost to reach that step by adding the cost
of that step to the minimum of the cost to reach the previous step and the step before that.
4. We can return the minimum cost to reach the top of the stairs, which is the minimum of the cost to reach the last step and the second to last step.

Time Complexity: O(n), where n is the number of steps.
Space Complexity: O(n), where n is the number of steps.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l = cost.size();
        vector<int> dp(l, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < l; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[l - 1], dp[l - 2]);
    }
};