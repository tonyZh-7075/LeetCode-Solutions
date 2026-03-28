/*
Monday, March 23rd, 2026

Topic: 2D Array, Dynamic Programming

Basic Idea:
We can use dynamic programming to solve this problem. 
We can modify the input grid to store the minimum path sum to reach each cell.
1. First, we can fill the first row and first column of the grid with the cumulative
    sums, since there is only one way to reach any cell in the first row or first column.
2. Then, for each cell in the grid starting from (1, 1), we can calculate the minimum path 
    sum to reach that cell by taking the minimum of the path sums from the top cell and the left cell, and adding the value of the current cell.
3. Finally, the minimum path sum to reach the bottom-right cell will be stored in the
    bottom-right cell of the grid, which we can return as the result.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        for (int i = 1; i < r; i++) {
            grid[i][0] = grid[i][0] + grid[i-1][0];
        }

        for (int j = 1; j < c; j++) {
            grid[0][j] = grid[0][j] + grid[0][j-1];
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[r-1][c-1];
    }
};