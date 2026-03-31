/*
Tuesday, March 31st, 2026

Topic: Dynamic Programming, String

Basic Idea:
We can use dynamic programming to solve this problem.
1. We can create a vector to store the number of ways to decode the string up to each position.
2. We can initialize the first element of the vector with 1, since there is one way to decode an empty string.
3. Then, for each position in the string, we can calculate the number of ways to decode it by considering 
the previous positions and the current character.


Time Complexity: O(n), where n is the length of the input string.

Notes:
- when the current character is '0', we need to check the previous character to see if it can form a 
valid two-digit number (10 or 20). 
- If it can, we can add the number of ways to decode up to the position before the previous character. (dp[i - 2])
- If it cannot, then there are no valid decodings for that position and we can return 0.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {


        int l = s.size();
        vector<int> dp(l, 0);

        if (l == 0) {
            return 1;
        }

        if (s[0] - '0' == 0) {
            return 0;
        } else {
            dp[0] = 1;
        }

        if (l == 2 && s[1] - '0' == 0) {
            if (s[0] - '0' <= 2) {
                return 1;
            } else {
                return 0;
            }
        }

        for (int i = 1; i < l; i++) {
            int cur = s[i] - '0';
            int prev = s[i - 1] - '0';
            int num = prev * 10 + cur;

            if (cur != 0) {
                if (num >= 10 && num <= 26) {
                    if (i == 1) {
                        dp[i] = dp[i - 1] + 1;
                    } else {
                        dp[i] = dp[i - 1] + dp[i - 2];
                    }
                } else {
                    dp[i] += dp[i - 1];
                }
            } else {
                if (num == 0 || num >= 30) {
                    return 0;
                } else {
                    if (i == 1) {
                        dp[i] += dp[i - 1];
                    } else {
                        dp[i] += dp[i - 2];
                    }
                }
            }
        }

        return dp[l - 1];
    }
};