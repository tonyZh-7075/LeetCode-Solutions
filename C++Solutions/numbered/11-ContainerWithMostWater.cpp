/*
Friday, April 3rd, 2026

Topic: Array, Two Pointers, Greedy

Basic Idea:
To solve the Container With Most Water problem, we can use the two-pointer approach. 
We initialize two pointers at the beginning and end of the array, and move the pointer pointing to the shorter line inward.
This is because moving the taller line inward will not increase the area, but moving the shorter line inward 
might lead to a larger area.

Time Complexity: O(n), where n is the number of elements in the input array, since we only need to traverse the array once.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans = 0;
        
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int leftHeight = height[left];
            int rightHeight = height[right];
            int width = right - left;
            int curArea = min(leftHeight, rightHeight) * width;
            ans = max(ans, curArea);

            if (leftHeight <= rightHeight) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};