/*
Wednesday, April 1st, 2026

Topic: Depth-First Search (DFS)

Basic Idea:
We can use depth-first search (DFS) to solve this problem.
1. We can start from the given starting pixel and check if it has the same color as
the original color. If it does, we can change its color to the new color.
2. Then, we can recursively call the DFS function for the four adjacent pixels (up,
down, left, right) to check if they also have the same color as the original color and change their color if they do.
3. We can continue this process until we have checked all the connected pixels with the same color
as the original color and changed their color to the new color.


Time Complexity: O(n), where n is the number of steps, since we may need to visit each pixel at most once.

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return image;

        dfs(image, sr, sc, color, orig);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int color, int orig) {
        int m = image.size();
        int n = image[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != orig) {
            return;
        }

        image[r][c] = color;

        dfs(image, r - 1, c, color, orig);
        dfs(image, r + 1, c, color, orig);
        dfs(image, r, c - 1, color, orig);
        dfs(image, r, c + 1, color, orig);
    }
};