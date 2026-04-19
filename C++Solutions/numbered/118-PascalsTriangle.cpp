/*
Thursday, April 16th, 2026

Topic: array, Simulation, dynamic programming (maybe)

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pastri(numRows);
        for (int i = 0; i < numRows; i++) {
            pastri[i] = vector<int>(i + 1);
        }

        pastri[0][0] = 1;
        for (int i = 1; i < numRows; i++) {
            int numCols = pastri[i].size();
            for (int j = 0; j < numCols; j++) {
                if (j == 0 || j == numCols - 1) {
                    pastri[i][j] = 1;
                } else {
                    pastri[i][j] = pastri[i - 1][j - 1] + pastri[i - 1][j];
                }
            }
        }
        return pastri;
    }
};