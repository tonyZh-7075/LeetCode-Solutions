/*
Saturday, March 28th, 2026

Topic: 2D Array, Simulation, 2D Matrix Traversal

Basic Idea:
We can use a vector of pairs to represent the 8 possible directions to check for live neighbors
for each cell in the board. 

We can iterate through each cell in the board and count the number of live neighbors 
by checking the 8 possible directions. 

We can use the value of the current cell to determine if it is currently alive or dead, 
and based on the count of live neighbors, we can determine if it will be alive or dead in the next state. 

We can use a temporary value to store the next state of each cell while we are counting the live neighbors, 
and then update the board with the next state after we have processed all cells.

To do it in-place, you need to traverse the board in two passes.

In the first pass, add 2 to the value of all cells that will be live in the next generation. Test whether neighbors are live or dead by checking if (cell % 2 == 1) instead of (cell == 1). This way, adding 2 to mark a cell as live in the next generation will not affect neighbors checking the cell's current state. After the first pass is complete, every cell will contain one of the following values:
0 : Dead now, dead in the next generation.
1: Live now, dead in the next generation.
2: Dead now, live in the next generation.
3: Live now, live in the next generation.

In the second pass, divide the value in each cell by 2 to get the final results for the next generation.
0, 1: Now 0, or dead.
2, 3: Now 1, or live.
*/

#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        int numRows = board.size();
        int numCols = board[0].size();

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {

                int countLiveNeighbours = 0;

                for (int k = 0; k < directions.size(); k++) {
                    int newi = i + directions[k].first;
                    int newj = j + directions[k].second;

                    if (newi >= 0 && newi < numRows && newj >= 0 && newj < numCols) {
                        if (board[newi][newj] % 2 == 1) {
                            countLiveNeighbours++;
                        }
                    }
                }

                if (board[i][j] == 0) {
                    if (countLiveNeighbours == 3) {
                        board[i][j] += 2;
                    }
                }

                if (board[i][j] == 1) {
                    if (countLiveNeighbours == 2 || countLiveNeighbours == 3) {
                        board[i][j] += 2;
                    }
                }
            }
        }

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                board[i][j] /= 2;
            }
        }
    }
};