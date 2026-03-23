/*
Sunday, March 22nd, 2026

Topic: 2D Array, searching

Basic Idea:
We can start searching from the top right corner of the matrix.
If the current element is equal to the target, we return true.
If the current element is less than the target, we can move down to the next row because
all the elements in the current column below the current element will be greater than the target.
If the current element is greater than the target, we can move left to the previous column because
all the elements in the current row to the left of the current element will be less than the
target.

This way we can efficiently search for the target in the 2D matrix without needing to check every element.

Time Complexity: O(m + n), where m is the number of rows and n is the number of columns in the matrix.

*/


#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;

        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }

            if (matrix[i][j] < target) {
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};