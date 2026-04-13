/*
Sunday, April 12th, 2026

Topic: Array

Basic Idea:
We iterate through the array from the starting index and look for the target element in 
both directions (left and right) simultaneously.


Time Complexity: O(n), where n is the length of the input array. 
Space Complexity: O(1), where n is the length of the input array.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int s = nums.size();
        int loopTermination = max(s - start, start + 1);
        for (int i = 0; i < loopTermination; i++) {
            if (start + i < nums.size()) {
                if (nums[start + i] == target) {
                    return i;
                }
            }

            if (start - i >= 0) {
                if (nums[start - i] == target) {
                    return i;
                }
            }
        }
        return -1;
    }
};
