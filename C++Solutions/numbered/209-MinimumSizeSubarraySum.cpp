/*
Wednesday, Februaruy 5th, 2026

Topic: Sliding Window, Two Pointers

Basic Idea:
We can use the sliding window technique to solve this problem.
1. We can initialize two pointers, i and j, to the beginning of the array and
a variable to keep track of the current sum of the window.
2. We can move the right pointer j to the right and add the value at j to
the current sum until the sum is greater than or equal to the target.
3. Once the sum is greater than or equal to the target, we can calculate the length
of the current window and update the minimum length if it is smaller than the previous minimum length.
4. Then, we can move the left pointer i to the right and subtract the value at
i from the current sum until the sum is less than the target.
5. We can repeat this process until we have checked all possible windows in the array.


Time Complexity: O(n), where n is the number of elements in the array, 
since we may need to visit each element at most twice.
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int largest = INT32_MAX;
        int windowSum = 0;
        int i = 0;
        int windowLength = 0;

        for (int j = 0; j < nums.size(); j++) {
            windowSum += nums[j];

            while (windowSum >= target) {
                windowLength = j - i + 1;
                largest = min(largest, windowLength);
                windowSum -= nums[i];
                i++;
            }
        }

        if (largest == INT32_MAX) {
            return 0;
        } else {
            return largest;
        }
    }
};