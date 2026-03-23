/*
Tuesday, March 17th, 2026

Topic: Array, Dynamic Programming

This is a bottom-up dynamic programming solution. 
We start from the second row and add the minimum path sum to each element. 
Finally, we find the minimum path sum in the last row.


ex:
original triangle:
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

after processing:
[
     [2],
    [5,6],
   [11,10,13],
  [15,11,18,16]
]

final answer is the minimum of the last row, which is 11.

*/

#include <vector>
#include <climits>
using namespace std;



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i-1][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i-1][j-1];
                } else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }

        vector<int> lastRow = triangle[triangle.size() - 1];
        int index = triangle.size() - 1;

        int ans = INT_MAX;

        for (int i = 0; i < lastRow.size(); i++) {
            ans = min(ans, triangle[index][i]);
        }

        return ans;
    }
};
