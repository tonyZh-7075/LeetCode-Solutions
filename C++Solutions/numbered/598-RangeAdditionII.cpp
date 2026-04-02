/*
Thursday, April 2nd, 2026

Topic: 2D Array, Math

Basic Idea:
To find the maximum count of integers in the matrix after performing the operations,
we simply find the minimum x and y values from the operations. 
The maximum count will be the product of these minimum values,
 as it represents the largest submatrix that can be incremented by all operations.


Time Complexity: O(k), where k is the number of operations, since we need to iterate through the list of operations once to find the minimum x and y values.

*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minX = INT_MAX;
        int minY = INT_MAX;

        if (ops.size() == 0) {
            return m * n;
        }

        for (int i = 0; i < ops.size(); i++) {
            minX = min(minX, ops[i][0]);
            minY = min(minY, ops[i][1]);
        }

        return minX * minY;
    }
};