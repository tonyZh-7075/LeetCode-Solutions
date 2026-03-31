/*
Monday, March 30th, 2026

Topic: Dynamic Programming

Basic Idea:
We can use dynamic programming to solve this problem.
1. We can create a 1D array of integers to store the number of ways to reach each step.
2. We can initialize the first two elements of the array with 1 and 2, since there is only one way to reach the first step and two ways to reach the second step.
3. Then, for each step from the third step onwards, we can calculate the number of ways to reach that step by adding the number of ways to reach the previous step and the step before that.
4. We can return the number of ways to reach the nth step.

Time Complexity: O(n), where n is the number of steps.

Notes:
- we can also optimize the space complexity to O(1) by only keeping track of the last two values instead of the entire array.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        if (n >= 2) {
            dp[1] = 2;
        }
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};



/* Optimized version uisng only variables:
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int cur = 2;

        if (n == 1) {
            return 1;
        }

        for (int i = 2; i < n; i++) {
            int a = prev;
            prev = cur;
            cur = a + cur;
        }
        return cur;
    }
};
*/