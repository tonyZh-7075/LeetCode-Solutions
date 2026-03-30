/*
Sunday, March 29th, 2026

Topic: 2D Array, Dynamic Programming

Basic Idea:
We can use dynamic programming to solve this problem.
1. We can create a 2D grid of integers to store the size of the largest square that can be formed at each position 
   in the original matrix.
2. We can initialize the first row and first column of the grid with the values from the original matrix, since the l
   argest square that can be formed at any position in the first row or first column is just the value of that position (either 0 or 1).
3. Then, for each cell in the grid starting from (1, 1), we can calculate the size of the largest square that 
   can be formed at that position by taking the minimum of the values from the top cell, left cell, and top-left diagonal cell in the grid, and adding 1 if the value of the current cell in the original matrix is 1 (indicating that it can be part of a square).
4. We can keep track of the maximum size of the square found so far, and at the end, we can return the area of 
   the largest square by squaring the maximum size. 

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.

Notes:
- the input matrix is of char type so we need to convert to int grid
- we need to deal with the first row and col separately
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> grid(m, vector<int>(n));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                grid[i][j] = matrix[i][j] - '0';
            }
        }

        int maxsq = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxsq = max(maxsq, grid[i][j]);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = min(grid[i-1][j-1], min(grid[i][j-1], grid[i-1][j])) + 1;
                }
                maxsq = max(maxsq, grid[i][j]);
            }
        }
        return maxsq * maxsq;
    }
};