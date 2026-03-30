/*
Sunday, March 29th, 2026

Topic: 2D Array, Dynamic Programming

Basic Idea:
similar to the unique paths problem, but we need to account for obstacles. 
We set the dp value to 0 for any cell that has an obstacle, 
and we can only add the values from the top and left cells if they are not obstacles.
same idea otherwise, dp[i][j] = dp[i-1][j] + dp[i][j-1], since we can only move down or right.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        if (m == 1 && n == 1) {
            return 1;
        }

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = 0;
                for (int k = i; k < m; k++){
                    obstacleGrid[k][0] = 0;
                }
                break;
            }
            obstacleGrid[i][0] = 1;
        }

        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                obstacleGrid[0][j] = 0;
                for (int k = j; k < n; k++){
                    obstacleGrid[0][k] = 0;
                }
                break;
            }
            obstacleGrid[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};