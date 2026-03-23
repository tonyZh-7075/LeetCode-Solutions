/*
Monday, March 23rd, 2026

Topic: 2D Array, Binary Search

This is a binary search solution. 
We treat the 2D matrix as a 1D sorted array and perform binary search on it.
Basic idea: instead of searching through the 2d matrix with nested loops or
conventionally flattening the 2d array into a 1d array, we come up with a smart way
to determine the row and column index of the middle element in the 2d matrix. We can do this by using the formula:
rowIndex = mid / numOfColumns
columnIndex = mid % numOfColumns
This way our solution is more efficient and we can perform binary search on the 2d matrix without extra space.

ex:

original 2d array:
[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 3

left = 0, right = 3 * 4 - 1 = 11
mid = 5
rowIndex = 5 / 4 = 1
columnIndex = 5 % 4 = 1
matrix[1][1] = 11 > target, so we update right = mid - 1... so on until we find the target or exhaust the search space.

*/

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numOfRows = matrix.size();
        int numOfColumns = matrix[0].size();

        int left = 0;
        int right = numOfRows * numOfColumns - 1;

        while (left <= right) {
            int mid = left + (right - left);
            int rowIndex = mid / numOfColumns;
            int columnIndex = mid % numOfColumns;

            if (matrix[rowIndex][columnIndex] == target) {
                return true;
            }

            if (matrix[rowIndex][columnIndex] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};