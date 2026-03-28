/*
Saturday, March 28th, 2026

Topic: 2D Array, Dynamic Programming

Basic Idea:
this is a more complex version of the minimum path sum problem. (64) 
We can use dynamic programming to solve this problem.
*/

#include <vector>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 1; i < r; i++) {
            matrix[i][0] = matrix[i][0] + min(matrix[i-1][0], matrix[i-1][1]);
            for (int j = 1; j < c - 1; j++) {
                matrix[i][j] = matrix[i][j] + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
            }
            matrix[i][c-1] = matrix[i][c-1] + min(matrix[i-1][c-2], matrix[i-1][c-1]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < c; i++){
            ans = min(ans, matrix[r-1][i]);
        }

        return ans;
    }
};